#ifndef HED_HAL_MOTOR_L298_INTERFACE_H_
#define HED_HAL_MOTOR_L298_INTERFACE_H_

void L298_INIT_void(void);
void L298_CC_void(u8 PORT, u8 INX, u8 INY);
void L298_CCW_void(u8 PORT, u8 INX, u8 INY);
void L298_FORWARD_void(void);
void L298_BACKWARD_void(void);
void L298_RIGHT_void(void);
void L298_LEFT_void(void);
void L298_SPEED_UP_void(void);
void L298_SLOW_UP_void(void);

#endif
