//
//  YadeaParamter.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/6/27.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface YadeaParamter : NSObject


//三色灯支持 三基色值 缺省为0[ R , G , B] 0x000000;
@property (assign, nonatomic) int  colorfulLight;

//延时关闭大灯 延迟关闭大灯（单位：秒），缺省0，最大值不超过30
@property (assign, nonatomic) Byte autoCloseLight;

//定时开灯开始时间 HH:mm
@property (strong, nonatomic) NSString *startTime;
//定时开灯结束时间 HH:mm
@property (strong, nonatomic) NSString *endTime;


@end
