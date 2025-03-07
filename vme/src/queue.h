/** @file
 * @brief Client connection read and write buffer queue.
 *
 * Classes that implement a buffer queue as a linked list for server input
 * and output over the hooked connections.
 * 
 * The queue is managed through the cQueue class which provides the normal
 * list management functions. The data contained within the list resides
 * within internal cQueueElem nodes that should be operated upon through
 * cQueue.
 */
#ifndef VME_QUEUE_H
#define VME_QUEUE_H

#include "essential.h"

#include <rapidjson/prettywriter.h>


/******************************************************************************
 * @brief Used for the nodes within a Queue list.
 *
 * Used to store data within a Queue as a node within the linked list that
 * makes up the Queue. The QueueElem node is part of a singularly linked list
 * with a reference to the next node in the list referenced by pNext.
 * 
 * There is no requirement that a node within the list must reference any data
 * so pData being a nullptr is a valid value and in which case nSize should
 * also be zero.
 * 
 * Within the node, data is treated as an array of bytes of nSize length. When
 * creating nodes using the character string constructure note that the data
 * stored within the node will identify as one byte longer than the string as
 * the '\0' string termination character is also added to the data array.
 * 
 *****************************************************************************/
class cQueueElem
{
    friend class cQueue;

public:
    cQueueElem(char *str, int copy = TRUE);
    cQueueElem(ubit8 *data, ubit32 len, int copy = TRUE);
    ~cQueueElem();

    ubit32 Bytes();
    ubit8 *Data();

    void SetNull();
    cQueueElem *PeekNext();

private:
    //! Reference to the array of byte data stored within the node.
    ubit8 *pData;

    //! Number of bytes of data stored within the byte array (it's length).
    ubit32 nSize;

    //! Reference to the next node in the list, or nullptr if the end.
    cQueueElem *pNext;
};


/******************************************************************************
 * @brief Provieds a data buffer queue for use by server input and output
 *        data streams.
 *
 * In managing the buffering of data streams read into and written out of the
 * server, Queue buffers are set up handle data to be sent to the client or as
 * as landing place for incoming data read for processing by the main server
 * loop.
 *****************************************************************************/
class cQueue
{
public:
    cQueue();
    ~cQueue();

    int IsEmpty();
    ubit32 Size();
    ubit32 Bytes();

    int Copy(ubit8 *data, ubit32 len);
    int Cut(ubit32 len);
    int CutCopy(ubit8 *data, ubit32 len);

    void Append(cQueueElem *node);
    void Prepend(cQueueElem *node);

    cQueueElem *GetHead();
    const cQueueElem *PeekHead();
    const cQueueElem *PeekTail();

    void Flush();

    void toJSON(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer) const;

private:
    //! Reference to the first node in the Queue list, nullptr if Queue empty.
    cQueueElem *pHead;

    //! Reference to the last node in the Queue list, nullptr if Queue empty.
    cQueueElem *pTail;

    //! A count of the number of nodes within the Queue list.
    ubit32 nEntries;

    //! A sum of all the bytes of data stored within the Queue list.
    ubit32 nBytes;
};

#endif /* VME_QUEUE_H */
