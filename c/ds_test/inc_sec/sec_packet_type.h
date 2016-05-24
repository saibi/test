/*!
 * \file sec_packet_type.h
 * \brief
 *
 *
 * created by Kim Youngmin (ymkim@huvitz.com)
 * creation date : �� 5 21  Korea Standard Time 2008
 *
*/
#ifndef _SEC_PACKET_TYPE_H_
#define _SEC_PACKET_TYPE_H_

enum sec_packet_type_idx {
	// default packet type
	PACKET_UNDEFINED, // <FS> ~~ <GS> �� ������ ��� packet
	PACKET_ACK,
	PACKET_NAK,
	PACKET_BARCODE,

	// 20090928 ��� �ĺ� packet
	PACKET_GETDEV = 101,
	PACKET_ANSDEV,

	// frame data ���� ��Ŷ Ÿ�� ����
	PACKET_REQ_SEND = 1001,
	PACKET_ANSWER,
	PACKET_DATA,
	PACKET_REQ_RECEIVE,
	PACKET_CFD, // CPE-4000 frame data restore ����� ���� 

	// Excelon Ez sync protocol ��Ŷ Ÿ�� ����
	PACKET_EZ_SYNC = 2001,
	PACKET_EZ_SYNC_FRAME,

	// CPE4000 GUI <-> Motor packet
	PACKET_CPE_MOTOR_CLAMP = 3001,
	PACKET_CPE_MOTOR_ERR_REQ,
	PACKET_CPE_MOTOR_ERR_ANS,
	PACKET_CPE_MOTOR_SWVER,
	PACKET_CPE_MOTOR_INIT,
	PACKET_CPE_MOTOR_EMERGENCY_INIT,
	PACKET_CPE_MOTOR_TEST_MODE,
	PACKET_CPE_MOTOR_ERROR,
	PACKET_CPE_MOTOR_PROGRESS_MODE,
	PACKET_CPE_MOTOR_INIT_CONFIRM,

	PACKET_CPE_MOTOR_CONF_DATA,  // 3011
	PACKET_CPE_MOTOR_FRAME_JOB, 
	PACKET_CPE_MOTOR_FRAME_JOB_CONFIRM, 
	PACKET_CPE_MOTOR_FRAME_DATA, 
	PACKET_CPE_MOTOR_PROCESS_MODE,
	PACKET_CPE_MOTOR_CLAMP_PRESSURE,
	PACKET_CPE_MOTOR_FRAME_SIZE,
	PACKET_CPE_MOTOR_EDGING_START,
	PACKET_CPE_MOTOR_CALIBRATION_START,
	PACKET_CPE_MOTOR_SIZE_CALIBRATION,

	PACKET_CPE_MOTOR_FEELER_CALIBRATION, // 3021
	PACKET_CPE_MOTOR_SBG_CALIBRATION,
	PACKET_CPE_MOTOR_CALIBRATION_FINISH,
	PACKET_CPE_MOTOR_AGING,
	PACKET_CPE_MOTOR_AGING_COUNTER,
	PACKET_CPE_MOTOR_RETOUCH_DATA,
	PACKET_CPE_MOTOR_SEQ_TEST_MODE, // 20080124 �߰� packet ����ȭ�� ���� 


	// HEX GUI <-> Motor packet
	PACKET_HMC_INIT = 3031,
	PACKET_HMC_VER,
	PACKET_HMC_START_JOB,
	PACKET_HMC_REQ_SENSOR_STATUS, // sensor ���� ��û
	PACKET_HMC_ANS_SENSOR_STATUS, // sensor ���� ���� 
	PACKET_HMC_CTRL_MOTOR, // motor control
	PACKET_HMC_CALIBRATION_DATA,
	PACKET_HMC_SESSION,
	PACKET_HMC_ROTATION_LIMIT,
	PACKET_HMC_ROTATION_SPEED,

	PACKET_HMC_WHEEL_SETTING, // 3041
	PACKET_HMC_SIZE_ADJ,
	PACKET_HMC_MARGIN_ADJ,
	PACKET_HMC_ADDITIONAL_MARGIN_ADJ,
	PACKET_HMC_AXIS_ADJ,
	PACKET_HMC_BEVEL_ADJ,
	PACKET_HMC_SB_ADJ,
	PACKET_HMC_GROOVE_ADJ,
	PACKET_HMC_FACTORY_SET1,
	PACKET_HMC_FACTORY_SET2,

	PACKET_HMC_FACTORY_SET3, // 3051
	PACKET_HMC_CLAMP_PRESSURE,
	PACKET_HMC_WINDOW,
	PACKET_HMC_EDGING_DATA,
	PACKET_HMC_DRILL_DATA,
	PACKET_HMC_CLAMP, 
	PACKET_HMC_ERROR, 
	PACKET_HMC_PROGRESS_MODE,
	PACKET_HMC_WORK_PROGRESS,
	PACKET_HMC_BUSY_STATUS, 

	PACKET_HMC_ANS_CALIB, // 3061
	PACKET_HMC_RETOUCH_PARAM,
	PACKET_HMC_ERR_REQ,
	PACKET_HMC_ERR_ANS,
	PACKET_HMC_DRILL_ADJ,
	PACKET_HMC_LIST, 
	PACKET_HMC_DRILL_ADJ2,
	PACKET_HMC_DRILL_ADJ3,
	PACKET_HMC_ERR_MSG,

	// CPE4000 GUI <-> Motor �޽��� ��/���� ��Ŷ 
	PACKET_COMM_BRATE=4001,
	PACKET_DUMP_LINE,
	PACKET_CMD_LINE,
	PACKET_BIN_START,
	PACKET_BIN_END,
	PACKET_ALIVE,
	PACKET_BEEP,






	MAX_SEC_PACKET_TYPE_IDX
};


#endif
/********** end of file **********/