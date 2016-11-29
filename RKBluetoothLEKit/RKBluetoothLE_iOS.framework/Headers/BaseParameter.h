//
//  BaseParameter.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/9.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RkFieldConverter.h"

#define  BT_SUCCESS           0
#define  BT_ERROR             1

#define  PARAM_READ           0
#define  PARAM_WRITE          1
//RK410 协议版本
#define  RK410_AUTH           0x00
#define  RK410_REBOOT         0x01
#define  RK410_MOTOR          0x02
#define  RK410_BATTERY        0x03
#define  RK410_ECU            0x04
#define  RK410_SYNC_TIME      0x09
#define  RK410_KEY_LIST       0x0C
#define  RK410_GEAR           0x0E
#define  RK410_MILEAGE        0x0F
#define  RK410_ELECTRIC_CU    0x12
#define  RK410_SPEED_CONFIG   0x13
#define  RK410_TURBO          0x14
#define  RK410_ENABLE_SERVICE 0x15
#define  RK410_CUSTOM_CONFIG  0x17
#define  RK410_INSTRUMENT     0x18
#define  RK410_CLEAR_MILEAGE  0x19
#define  RK410_VERSION        0xF1
#define  RK410_UDID           0xF2

@interface BaseParameter : NSObject<RkFieldConverter>

//读写类型
@property (nonatomic,assign) int    method;
//指令
@property (nonatomic,assign) int    command;
//长度
@property (nonatomic,assign) int    length;
//参数
@property (nonatomic,strong) NSData *org;

-(NSData*)createQueryCommand;

@end
