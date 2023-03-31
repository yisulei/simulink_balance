function stacklite_dualdrive_callback_handler(hDlg,hSrc)

%-------StartTime--------%
slConfigUISetVal(hDlg,hSrc,'StartTime','0.0');
slConfigUISetEnabled(hDlg,hSrc,'StartTime',false);

%-------StopTime--------%
slConfigUISetVal(hDlg,hSrc,'StopTime','inf');
slConfigUISetEnabled(hDlg,hSrc,'StopTime',false);

%-------选择为定步长--------%
slConfigUISetVal(hDlg,hSrc,'SolverType','Fixed-step');
slConfigUISetEnabled(hDlg,hSrc,'SolverType',false);

%----设置固定步长-----%
slConfigUISetVal(hDlg,hSrc,'FixedStep','0.0005');
slConfigUISetEnabled(hDlg,hSrc,'FixedStep',false);

%-------设置为离散模式--------%
slConfigUISetVal(hDlg,hSrc,'SolverName','FixedStepDiscrete');
slConfigUISetEnabled(hDlg,hSrc,'SolverName',false);

%-------指定硬件目标为ARM--------%
slConfigUISetVal(hDlg,hSrc,'ProdHWDeviceType','ARM Compatible');
slConfigUISetVal(hDlg,hSrc,'ProdHWDeviceType','ARM Cortex');
slConfigUISetEnabled(hDlg,hSrc,'ProdHWDeviceType',false);

%-------指定系统tlc文件-------%
%slConfigUISetVal(hDlg,hSrc,'SystemTargetFile','stacklite_dualdrive.tlc');
%slConfigUISetEnabled(hDlg,hSrc,'SystemTargetFile',false);

%--------设置默认生成代码报告------%
slConfigUISetVal(hDlg,hSrc,'GenerateReport','on');
slConfigUISetEnabled(hDlg,hSrc,'GenerateReport',false);

%-------取消生成ert_main.c函数-----%
slConfigUISetVal(hDlg,hSrc,'GenerateSampleERTMain','off');
slConfigUISetEnabled(hDlg,hSrc,'GenerateSampleERTMain',false);

%-------接口-高级-目标支持C++类接口-----%
slConfigUISetVal(hDlg,hSrc,'CPPClassGenCompliant','on');
slConfigUISetEnabled(hDlg,hSrc,'CPPClassGenCompliant',false);

%-------接口-高级-目标支持并行模型引用编译-----%
slConfigUISetVal(hDlg,hSrc,'ParMdlRefBuildCompliant','on');
slConfigUISetEnabled(hDlg,hSrc,'ParMdlRefBuildCompliant',false);

%-------接口-高级-目标支持编译器优化级别控制-----%
slConfigUISetVal(hDlg,hSrc,'CompOptLevelCompliant','on');
slConfigUISetEnabled(hDlg,hSrc,'CompOptLevelCompliant',false);

%-------接口-高级-目标支持模型引用-----%
slConfigUISetEnabled(hDlg,hSrc,'ModelReferenceCompliant',true);
slConfigUISetVal(hDlg,hSrc,'ModelReferenceCompliant','on');
hSrc.refreshDialog;




