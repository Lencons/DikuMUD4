#pragma once

#include "essential.h"

#include <string>

std::string player_filename(const char *);
int delete_inventory(const char *player_name);
int delete_player(const char *player_name);
int find_player_id(char *player_name);
int player_exists(const char *player_name);
int max_player_id(void);
void save_player(unit_data *pc);
unit_data *load_player(const char *pName);
void save_player_contents(unit_data *pc, int fast);
sbit32 new_player_id();
void assign_player_file_index(unit_data *pc);
void save_player_file(unit_data *pc);
void player_file_index();

extern sbit32 g_player_id;
