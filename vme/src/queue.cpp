/** @file
 * @brief Input and Output data Queue functionality.
 *
 * The buffering of data to be read from and written to clients of the
 * application server is performed through this implementation of Queues.
 * These Queues provide a linked list of data nodes.
 * 
 * This file provdes the method definitions for the two classes that make up
 * the Queue processing:
 *      Queue       Provides all of the functionality of the queue.
 *      QueueElem   Container for the nodes within the list storing data.
 * 
 */


#include <cassert>
#include <cstring>

#include "queue.h"
#include "slog.h"

#include "json_helper.h"
#include "utility.h"


/******************************************************************************
 * @brief Constructor to create a Queue Element containing a string.
 *
 * Creates a new cQueueElem object containing the character string provided
 * in str. The constructor can use the provided str pointer and use that
 * memory reference within the element, or if copy is set to a non-zero value
 * then the string at str will be copied to a new memory location and stored
 * into the Queue Element.
 *
 * @param str       Pointer to the character string containing the source data.
 * @param copy      Flag on if the source string is to be copied into a new
 *                  memory location, or use the provided memory reference.
 * @return          A new cQueueElem object.
 *****************************************************************************/
cQueueElem::cQueueElem(char *str, int copy)
{
    nSize = 0;

    if ((str == nullptr) || (*str == '\0')) {
        slog(LOG_ALL, 0, "Warning - Added empty string to Queue.");
        nSize = 0;
        pData = nullptr;
    } else {
        nSize = strlen(str) + 1;

        if (copy == 0) {
            pData = (ubit8 *)str;
        } else {
            CREATE(pData, ubit8, nSize);
            memcpy(pData, str, nSize);
        }
    }
}


/******************************************************************************
 * @brief Constructor to create a Queue Element containing binary data.
 *
 * Creates a new cQueueElem object containing the byte data provided. The
 * constructor can use the provided data pointer and use this memory reference
 * within the element, or if copy is set to a non-zero value then the source
 * data will be copied to a new memory location and stored into the Queue
 * Element.
 *
 * @param data      Pointer to an array of source byte data.
 * @param len       Length of the source data array in bytes.
 * @param copy      Flag on if the source string is to be copied into a new
 *                  memory location, or use the provided memory reference.
 * @return          A new cQueueElem object.
 *****************************************************************************/
cQueueElem::cQueueElem(ubit8 *data, ubit32 len, int copy)
{
    if ((data == nullptr) || (len == 0)) {
        slog(LOG_ALL, 0, "Warning - Added empty data to Queue.");
        nSize = 0;
        pData = nullptr;
    } else {
        nSize = len;

        if (copy == 0) {
            pData = data;
        } else {
            CREATE(pData, ubit8, nSize);
            memcpy(pData, data, nSize);
        }    
    }
}


/******************************************************************************
 * @brief Destructor for a cQueueElem object.
 *
 * When the Queue node is destroyed, we need to make sure that any data
 * referenced by pData is also freed to ensure we don't leak memory.
 *****************************************************************************/
cQueueElem::~cQueueElem()
{
    if (pData != nullptr) {
        FREE(pData);
    }
}


/******************************************************************************
 * @brief Wrapper function to return the number of bytes of data stored within
 *        the Queue.
 *
 * Simple wrapper function to return the total number of bytes of data stored
 * across all nodes within the list.
 * 
 * @return          Number of bytes of data stored within the Queue.
 *****************************************************************************/
ubit32 cQueueElem::Bytes()
{ 
    return nSize;
}

/******************************************************************************
 * @brief Wrapper function to return a reference to the data stored within the
 *        Queue node.
 *
 * Simple wrapper function to return the pData reference to the data stored
 * within this Queue node.
 * 
 * @note    Nodes within the Queue are not required to have a reference to any
 *          data. So it is possible for a QueueElem to have a pData nullptr
 *          reference.
 * 
 * @return          Pointer to the stored data array.
 *****************************************************************************/
ubit8 *cQueueElem::Data()
{
    return pData;
}


/******************************************************************************
 * @brief Clears any reference to stored data for the node.
 *
 * Resets the QueueElem node to not reference or be storing any data by setting
 * all data references to NULL, zero or empty string.
 * 
 * @note    This method just clobbers any data that this Queue node is
 *          referencing. This is performed without updating the Queue data
 *          content count or attempting to free any existing memory referenced
 *          by the node. This method should be used very cautiously.
 * 
 *****************************************************************************/
void cQueueElem::SetNull()
{
    pData = nullptr;
    nSize = 0;
}


/******************************************************************************
 * @brief Wrapper function to get the reference to next node in the Queue.
 *
 * Simple wrapper function to return the reference to the next QueueElem node
 * within the list. The Queue itself and the data within the node is left
 * unmodified.
 * 
 * @return          Pointer to the next node in the Queue.
 *****************************************************************************/
cQueueElem *cQueueElem::PeekNext()
{
    return pNext;
}


/******************************************************************************
 * @brief Constructor to create a Queue for server input and output
 *        communication.
 *
 * Creates a new empty cQueue object.
 *
 * @return          A new empty cQueueobject.
 *****************************************************************************/
cQueue::cQueue()
{
    pHead = nullptr;
    pTail = nullptr;
    nEntries = 0;
    nBytes = 0;
}


/******************************************************************************
 * @brief Destructor for a cQueue object.
 *
 * Calls Flush() to destroy any cQueueElem elements within the Queue list.
 *****************************************************************************/
cQueue::~cQueue()
{
    Flush();
}


/******************************************************************************
 * @brief Return the number of nodes within the cQueue list.
 *
 * Simple wrapper function to return the number of list nodes stored in
 * nEntries.
 * 
 * @return          The value stored in nEntries.
 *****************************************************************************/
ubit32 cQueue::Size()
{
    return nEntries;
}


/******************************************************************************
 * @brief Return the number of bytes stored across nodes within the cQueue
 *        list.
 *
 * Simple wrapper function to return the number of bytes recorded within
 * nBytes. This is a managed aggregation of all nodes nSize value to provide
 * a total number of bytes currently stored within the queue.
 * 
 * @note This byte size value includes the null terminator of any string data
 *       that was added into the Queue. All string data is effectively
 *       converted to byte data when pushed into the Queue, so the returned
 *       bytes value will be larger than what was pushed as a character string.
 * 
 * @return          The value stored in nEntries.
 *****************************************************************************/
ubit32 cQueue::Bytes()
{
    return nBytes;
}


/******************************************************************************
 * @brief Wrapper function to test if there are any nodes within the Queue.
 *
 * Simple wrapper function to return the number of list nodes stored in
 * nEntries.
 * 
 * @return          If there are nodes in the Queue, a zero value is returned,
 *                  otherwise a non-zero value on empty Queue.
 *****************************************************************************/
int cQueue::IsEmpty()
{
    return nEntries == 0;
}


/******************************************************************************
 * @brief Copy a specific number of bytes from the Queue to an external buffer.
 *
 * Data will be copied from the Queue into the external buffer provided by the
 * data pointer. The nodes in the Queue will be tranversed until len bytes of
 * data have been copied.
 * 
 * If the number of bytes currently contained within the Queue is less than the
 * requested number of bytes to be copied, then the bytes beyond the copied
 * Queue data are zeroed out.
 * 
 * @param data      Pointer to external data buffer.
 * @param len       Number of bytes to copy to the external data buffer.
 * @return          Number of bytes copied into the buffer.
 *****************************************************************************/
int cQueue::Copy(ubit8 *data, ubit32 len)
{
    int byte_cnt = 0, copy_cnt;
    cQueueElem *qe = nullptr;

    // clean the buffer, ensures that any unused bytes will be zero.
    memset(data, 0, len);

    if (IsEmpty()) {
        return 0;
    }

    qe = (cQueueElem *)PeekHead();
    do {
        copy_cnt = MIN(len, qe->Bytes());
        memcpy(data, qe->Data(), copy_cnt);
        len -= copy_cnt;
        data += copy_cnt;
        byte_cnt += copy_cnt;
        qe = qe->PeekNext();
    } while (len > 0);

    return byte_cnt;
}


/******************************************************************************
 * @brief Cut (gobble) a specific number of bytes from the Queue.
 *
 * Cutting bytes from the Queue which is the same as gobbling them from the
 * Queue. The number of bytes provided in len will be removed from the Queue.
 * 
 * @param len       Number of bytes to copy to the external data buffer.
 * @return          Number of bytes removed from the Queue.
 *****************************************************************************/
int cQueue::Cut(ubit32 len)
{
    int cut_cnt = 0;
    cQueueElem *qe = nullptr;

    if (len < 1) {
        return 0;
    }

    do {
        // Remove the next node from the Queue.
        qe = GetHead();
        if (qe == nullptr) {
            break;
        };

        // If there is more data in the removed node, create a new node with
        // the remaining data.
        if (len < qe->Bytes()) {
            Prepend(new cQueueElem(qe->Data() + len, qe->Bytes() - len));
        }

        len -= MIN(qe->Bytes(), len);
        delete qe;
    } while (len > 0);

    return cut_cnt;
}


/******************************************************************************
 * @brief Remove the specific number of bytes from the Queue to an external
 *        buffer.
 *
 * Data will be copied from the Queue into the external buffer provided by the
 * data pointer with the copied data also being removed from the Queue.
 * 
 * If the number of bytes currently contained within the Queue is less than the
 * requested number of bytes to be copied, then the bytes beyond the copied
 * Queue data are zeroed out.
 * 
 * @param data      Pointer to external data buffer.
 * @param len       Number of bytes to copy to the external data buffer.
 * @return          Number of bytes copied into the buffer.
 *****************************************************************************/
int cQueue::CutCopy(ubit8 *data, ubit32 len)
{
    // We are assuming here that the number of Copy() bytes is the same as the
    // number of Cut() bytes for simplicity..... this should be the case.
    Copy(data, len);
    return Cut(len);
}


/******************************************************************************
 * @brief Add a new QueueElem node to the end of the Queue.
 *
 * Push a new node onto the end of the Queue.
 * 
 * @param node      QueueElem node to add to the end of the Queue.
 *****************************************************************************/
void cQueue::Append(cQueueElem *node)
{
    if (IsEmpty()) {
        pHead = pTail = node;
    } else {
        pTail->pNext = node;
        pTail = node;
    }

    node->pNext = nullptr;

    nEntries++;
    nBytes += node->Bytes();
}


/******************************************************************************
 * @brief Add a new QueueElem node to the front/start of the Queue.
 *
 * Push a new node onto the head of the Queue.
 * 
 * @param node      QueueElem node to add to the front of the Queue.
 *****************************************************************************/
void cQueue::Prepend(cQueueElem *node)
{
    if (IsEmpty()) {
        node->pNext = nullptr;
        pTail = node;
    } else {
        node->pNext = pHead;
    }

    pHead = node;

    nEntries++;
    nBytes += node->Bytes();
}


/******************************************************************************
 * @brief Wrapper function to get the reference to the head of the Queue.
 *
 * Simple wrapper function to return a reference to the QueueElem node at the
 * head of the Queue. The Queue itself and the data within the Queue is left
 * unmodified.
 * 
 * @return          Pointer to the first node in the Queue.
 *****************************************************************************/
const cQueueElem *cQueue::PeekHead()
{
    return pHead;
}


/******************************************************************************
 * @brief Wrapper function to get the reference to the tail of the Queue.
 *
 * Simple wrapper function to return a reference to the QueueElem node at the
 * end of the Queue. The Queue itself and the data within the Queue is left
 * unmodified.
 * 
 * @return          Pointer to the first node in the Queue.
 *****************************************************************************/
const cQueueElem *cQueue::PeekTail()
{
    return pTail;
}


/******************************************************************************
 * @brief Remove the node from the head of the Queue.
 *
 * The QueueElem node currently as the head of the Queue is popped out of the
 * list and a reference to it is returned.
 * 
 * @return          Pointer to the node removed from the Queue.
 *****************************************************************************/
cQueueElem *cQueue::GetHead()
{
    cQueueElem *p = nullptr;

    if (IsEmpty()) {
        return nullptr;
    }

    p = pHead;

    if (nEntries == 1) {
        pHead = pTail = nullptr;
    } else {
        pHead = pHead->pNext;
    }

    nEntries--;
    nBytes -= p->Bytes();

    return p;
}


/******************************************************************************
 * @brief Flush the Queue, destroying all data current contained within it.
 *
 * Flushing the Queue removes all nodes currently within the list and resets
 * the Queue back to a empty list.
 * 
 * @note    All QueueElem nodes that are removed from the Queue are destroyed
 *          making any external references to the memory invalid.
 * 
 *****************************************************************************/
void cQueue::Flush()
{
    cQueueElem *p = nullptr;

    while ((p = GetHead()) != nullptr) {
        delete p;
    }
}


void cQueue::toJSON(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer) const
{
    writer.StartObject();
    {
        json::write_kvp("Entries", nEntries, writer);
        json::write_kvp("Bytes", nBytes, writer);
    }
    writer.EndObject();
}
