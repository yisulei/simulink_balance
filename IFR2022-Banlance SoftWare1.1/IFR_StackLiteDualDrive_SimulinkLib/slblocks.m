function blkStruct = slblocks

Browser.Library = 'IFR_StackLiteDualDrive_SimulinkLib'; %与创建的库的名字相同
Browser.Name    = 'IFR_StackLiteDualDrive_SimulinkLib_V1.0';% 展示在页面上的名字
Browser.IsFlat  = 0; % 0表示没有子模块；1表示存在子模块
blkStruct.Browser = Browser;%默认这样就行