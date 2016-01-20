/*!
 * \file symbol_table.h
 * \brief
 *
 * symbol table for debugging
 *
 * created by Kim Youngmin (ymkim@huvitz.com)
 * creation date : ��  6�� 02 17:33:42 KST 2006
 *
*/
#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_


#include "llist.h"


// symbol table ����ü
struct symbol_table_entry {
	char *var_name;
	char **base; // structure �� field �� ����� �� ���
	void *addr;
	int addr_size;
	int bit_mask; // int(char) bit field ����� �� (0x01 ~ 0xffffffff)
			// 20081125 Ȥ�� string ��½� string size (���� �ڵ� ������ �ּ�ȭ �ϱ�����)


	// bit_mask �� ���� �Լ� parameter ������ Ʋ�� �� �־ void * �� ���� 
	void *pr_func; 
	void *set_func;

	// old fixed prototype
	//void (*pr_func)(void *addr);
	//void (*set_func)(void *addr, void *value);
	struct list_head list;
};


extern struct list_head symbol_table;




int insert_symbol_table_ex(char *var_name, void * base, void *addr, int addr_size, int bit_postion, void *pr_func, void *set_func);
struct symbol_table_entry * find_symbol(char *var_name);
void list_symbol_table(char *, int );
struct symbol_table_entry * search_pattern_in_symbol_table(char *ptn);

void print_symbol_contents(struct symbol_table_entry * entry, int index);
void set_symbol_contents(struct symbol_table_entry * entry, int index, void * value);


/// �Ϲ� ���� ���
#define insert_symbol_table(var_name, addr, addr_size, pr_func, set_func) insert_symbol_table_ex( var_name, NULL, addr, addr_size, 0,  (void*)(pr_func), (void*)(set_func))

/// �Ϲ� ���� bit ���
#define insert_symbol_table_bit(var_name, addr, addr_size, bit, pr_func, set_func) insert_symbol_table_ex( var_name, NULL, addr, addr_size, bit,  (void*)(pr_func), (void*)(set_func))

/// string ���
#define insert_symbol_table_str(var_name, addr, addr_size) insert_symbol_table_ex(var_name, NULL, addr, addr_size, addr_size, (void*)(print_string), (void*)(set_string))

/// structure field ���
/// \param base structure ������ �ּҸ� �ٷ� �ѱ��� ���� indirect �� �Ѱܾ� �Ѵ�.
#define insert_symbol_table_sf(var_name, indirect_base, offset, addr_size, pr_func, set_func) insert_symbol_table_ex( var_name, indirect_base, (void*)(offset), addr_size, 0, (void*)(pr_func), (void*)(set_func))


#define INSERT_INT_SYM( symname ) insert_symbol_table(#symname, &symname, sizeof(int), print_int, set_int)
#define INSERT_INT_SYM2( symstr, symname ) insert_symbol_table(symstr, &symname, sizeof(int), print_int, set_int)
#define INSERT_BYTE_SYM( symname ) insert_symbol_table(#symname, &symname, sizeof(char), print_char, set_char_int)
#define INSERT_FLOAT_SYM( symname ) insert_symbol_table(#symname, &symname, sizeof(float), print_float, set_float)

#endif 
/********** end of file **********/
