//
//  NSBundle+YEPickerView.h
//  YEPickerView
//
//  Created by yongen on 19/10/18.
//  Copyright © 2017年 yongen. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSBundle (YEPickerView)

/// 获取 YEPickerView.bundle
+ (instancetype)ye_pickerBundle;

/// 获取国际化后的文本
/// @param key 代表 Localizable.strings 文件中 key-value 中的 key。
/// @param language 设置语言（可为空，为nil时将随系统的语言自动改变）
+ (NSString *)ye_localizedStringForKey:(NSString *)key language:(NSString *)language;

@end

NS_ASSUME_NONNULL_END
