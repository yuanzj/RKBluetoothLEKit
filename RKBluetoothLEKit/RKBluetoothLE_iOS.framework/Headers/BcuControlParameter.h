//
//  BcuControlParameter.h
//  RokyinfoBLEDemo
//
//  Created by virgil on 2018/9/11.
//  Copyright © 2018年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseParameter.h"

@interface BcuControlParameter : BaseParameter
@property (assign, nonatomic) Byte type;
@property (assign, nonatomic) Byte orgs;

@end
