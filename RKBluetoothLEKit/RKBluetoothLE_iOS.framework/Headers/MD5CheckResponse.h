//
//  MD5CheckResponse.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/12.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import "BaseUpgradeResponse.h"

@interface MD5CheckResponse : BaseUpgradeResponse

//原因
@property (assign, nonatomic) Byte reason;

@end
