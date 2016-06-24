//
//  RequestPackageRespond.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/12.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseUpgradeResponse.h"

@interface RequestPackageResponse : BaseUpgradeResponse

//0：错误
//1：正常

//原因
@property (assign, nonatomic) Byte  reason;

@property (nonatomic,assign ) short packageIndex;

@property (nonatomic,assign ) int   packageCount;

@end
