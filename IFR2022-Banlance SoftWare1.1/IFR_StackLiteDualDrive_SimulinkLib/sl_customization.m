function sl_customization(cm)
% 更改自定义库在库浏览器中的排序
%写入需要改排序的库
% simulink优先级-1，其他库优先级0，设置-2优先级可以在第一位
cm.LibraryBrowserCustomizer.applyOrder({'IFR_StackLiteDualDrive_SimulinkLib',-2});
 
end