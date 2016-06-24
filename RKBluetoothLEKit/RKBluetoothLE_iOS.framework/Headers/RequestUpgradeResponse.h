//
//  RequestUpgradeResponse.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/12.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseUpgradeResponse.h"


@interface RequestUpgradeResponse : BaseUpgradeResponse

//0：不升级
//1：全新升级
//2：继续升级

//已下载文件
@property (assign, nonatomic) int downloadedLength;


@end
