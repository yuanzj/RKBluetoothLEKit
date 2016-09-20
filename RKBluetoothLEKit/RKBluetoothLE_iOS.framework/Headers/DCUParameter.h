//
//  DCUParameter.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/9/19.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseParameter.h"

@interface DCUParameter : BaseParameter
//    0：关闭服务, 1 开启服务
@property (nonatomic,assign  ) Byte     configFlag;
 //    0：RK600, 1：RK610 （RS485方式）
@property (nonatomic,assign  ) Byte     deviceType;

@property (nonatomic,assign  ) Byte     gpsSignal;

@property (nonatomic,assign  ) Byte     gsmSignal;

@property (nonatomic,copy    ) NSString *IMEI;

@end
