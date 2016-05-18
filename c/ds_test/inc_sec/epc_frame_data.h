/*!
 * \file epc_frame_data.h
 * \brief
 *
 * frame data �ۼ��� ��Ŷ ����
 *
 * created by Kim Youngmin (ymkim@huvitz.com)
 * creation date : ��  6�� 26 14:40:48 KST 2006
 *
*/
#ifndef _EPC_FRAME_DATA_H_
#define _EPC_FRAME_DATA_H_

#include "epc_type_def.h"

// frame data parameter
// �� �ʵ尪�� ���� ���� �����ϴ� (float �� �״�� ����� ��)
struct epc_frame_data {
	int data_type; // 0x01 +layout option, 0x02 +edging option, 0x04 + dp option, see EPC_ISO16284_ xxxx 
	int side; // 0 -right, 1-left
	int frame_type; // 0 - metal , 1 - plastic, 2 - optyl, 3 - pattern
	float frame_curve; // ������ Ŀ�� 
	float cir; // �ѷ� ���� 
	float angle_3d; // not used
	int record_number; // ������ ���� (������ 1440 �̾���Ѵ�)
	float r[MAX_RECORD_SIZE]; // radius �� 
	float a[MAX_RECORD_SIZE]; // angle �� 
	float fpd;  // fpd �� 

	// Ȯ�� ���� (layout)
	int vision_mode; // vision mode  0-far, 1-bifocal, 2-bifocal(circle)
	float bifocal_offset_h; // bifocal ��忡�� blocking offset
	float bifocal_offset_v;
	float bifocal_dia; // �ٿ�� ũ�� (����)
	float bridge_size; // bridge size
	float single_pd; // single pd
	float delta_y; // delta y

	int blocking_mode; // 0 - boxing, 1 - optical
	int oh_type; // 0 - delta_y, 1- boxed_h, 2- mixed_h

	// Ȯ�� ���� 2 (dp, edging option)
	float dp_down; // digital pattern ���� 
	float dp_updown;
	float dp_leftright;
	float dp_radius;
	float dp_percent;
	float dp_rotate;

	int fragile_mode; // 0-off/1-on
	int lens_material; // 0 pl, 1 pc, 2 hi, 3 gl, 4 tri
	int edging_type; // 0 rimless, 1 bevel, 2 grooving

	int polish; // 0-off/1-on
	int sb_front; // 0-off/1-on
	int sb_rear; // 0-off/1-small/2-large

	int bevel_pos_type; // 0-percent, 1-front, 2-rear, 3-bc (bevel/grooving position)
	float bevel_pos_value; // bevel ��ġ �� (type  ����)
	float size; // ���� ũ�� 

	float grooving_depth;
	float grooving_width;
};

int epc_frame_data_to_iso16284(char *buf, struct epc_frame_data *param, int count);
int iso16284_to_epc_frame_data(char *buf, struct epc_frame_data *param, int count);

void epc_frame_data_to_file(char *write_buf, struct epc_frame_data *param);
int file_to_epc_frame_data(char *in_buf, struct epc_frame_data *param, int max_count);

#endif
/********** end of file **********/
