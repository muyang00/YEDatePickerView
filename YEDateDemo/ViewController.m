//
//  ViewController.m
//  YEDateDemo
//
//  Created by huodada-yongen on 2023/1/18.
//

#import "ViewController.h"
#import "YEDatePickerView.h"

@interface ViewController ()

@property (nonatomic, strong) YEDatePickerView *datePickerView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSString *format = @"yyyy-MM-dd HH:mm:ss";
    
    UIView *containerView = [[UIView alloc]initWithFrame:CGRectMake(10, 260, self.view.frame.size.width - 20, 246)];
    containerView.backgroundColor = [UIColor secondarySystemBackgroundColor];
    [self.view addSubview:containerView];
    // 4.创建日期选择
    YEDatePickerView *datePickerView = [[YEDatePickerView alloc]init];
    datePickerView.pickerMode = YEDatePickerModeYMDHMS;
    
  
    NSString *minTimeString = @"2021-10-20 15:26:12";
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc]init];
    dateFormatter.locale = [NSLocale systemLocale];
    dateFormatter.dateFormat = format;
    NSDate *minDate = [dateFormatter dateFromString:minTimeString];
//    datePickerView.minDate = minDate;
//
//    datePickerView.maxDate = [NSDate date];
    datePickerView.numberFullName = YES;
    datePickerView.isAutoSelect = YES;
    datePickerView.showUnitType = YEShowUnitTypeAll;
    datePickerView.resultBlock = ^(NSDate *selectDate, NSString *selectValue) {
     
    };
    
    // 自定义选择器主题样式
    YEPickerStyle *customStyle = [[YEPickerStyle alloc]init];
    customStyle.pickerColor = containerView.backgroundColor;
    customStyle.separatorColor = UIColor.purpleColor;
    datePickerView.pickerStyle = customStyle;
    self.datePickerView = datePickerView;
    
    // 添加选择器到容器视图
    [datePickerView addPickerToView:containerView];
}


@end
