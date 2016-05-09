//
//  ECUParameter.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/9.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseParameter.h"

@interface ECUParameter : BaseParameter

//震动级别 0：表示最敏感，2：最不敏感，缺省为1
@property (assign, nonatomic) Byte gSensor;

//震动告警方式 0：声光同时，1：灯光告警，2：声音告警，3：铁喇叭+灯光告警，缺省：1
@property (assign, nonatomic) Byte alarmType;

//液晶显示方式 0：电控温度，1：电机扭矩，2：刹车再生能量，缺省：0
@property (assign, nonatomic) Byte LCD_DisplayType;

//档位切换类型 0：缺省三档切换控制；1：拨档2档控制；缺省：0
@property (assign, nonatomic) Byte gearsSwitchType;

//自动锁车时间 单位：分钟，缺省为2分钟
@property (assign, nonatomic) Byte autoSafety;

//锁开关 0：一键启动锁（沿触发）/ 1：传统钥匙锁（电平触发）2：无钥匙开关，仅依赖手机或传统遥控器进行操作-
@property (assign, nonatomic) Byte lockType;

//国标限速开关 0:限速关闭， 1：限速开启，缺省 限速关闭
@property (assign, nonatomic) Byte speedLimitSwitch;

//国标限速PWM缺省值 限速情况下百分比值（确保限制在20KM/H内），缺省值：50
@property (assign, nonatomic) Byte defaultPwmSpeedLimit;

//喇叭音量大小 0,1,2分别表示低，中，高三档音量
@property (assign, nonatomic) Byte hornVolume;

//童锁开关 0：不支持P档（即使按键也不响应），1：支持童锁功能开启，需按P档键进入或退出P档2：支持上电P档，即上电缺省进P档，需按P档解除缺省值：1
@property (assign, nonatomic) Byte childLock;

//液晶屏幕编码 对应液晶编码，缺省为0，对应车精灵2.0屏幕
@property (assign, nonatomic) Byte screenCode;

//传统遥控器支持开关 0：不支持，缺省值，1 支持
@property (assign, nonatomic) Byte remoteControllerSupport;

//背景灯效果 0：常规背景灯效果；1：三色灯常规效果；2：三色灯变换效果—具体待定义 缺省：0
@property (assign, nonatomic) Byte backlightEffect;

//三色灯支持 三基色值 缺省为0[ R , G , B] 0x000000;
@property (assign, nonatomic) int  colorfulLight;

//延时关闭大灯 延迟关闭大灯（单位：秒），缺省0，最大值不超过30
@property (assign, nonatomic) Byte autoCloseLight;

+(ECUParameter*)createDefault;

@end
