//
//  UEVersionResponse.h
//  RokyinfoBLEDemo
//
//  Created by Yuan ZhiJian on 2016/11/29.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import "BaseParameter.h"
//0 ：CCU  1:ECU  2:PCU
typedef NS_ENUM(NSInteger, UEType)
{
    CCU       = 0,
    ECU       = 1,
    PCU       = 2,
    DCU       = 3,
    BCU       = 4,
};

@interface UEVersionResponse : BaseParameter

@property(nonatomic,assign)UEType type;

@property(nonatomic,copy)NSString *sVersion;

@property(nonatomic,copy)NSString *hVersion;

@end
