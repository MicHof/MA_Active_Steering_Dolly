function runtlccmd
% RUNTLCCMD - run tlc command (regenerate C code from .rtw file) for model demo_simplemodel
% This function will run the tlc command stored in the variable 
% "tlccmd" in tlccmd.mat, whose contents is as follows:
% 
% 	tlc
% 	-r
% 	C:\Users\Sebastian\Desktop\DBC_Files\RTICANMMDemo_SimpleModel\demo_simplemodel_rti1401\demo_simplemodel.rtw
% 	C:\Program Files\dSPACE RCPHIL 2014-A\MATLAB\RTI\RTI1401\TLC\rti1401.tlc
% 	-OC:\Users\Sebastian\Desktop\DBC_Files\RTICANMMDemo_SimpleModel\demo_simplemodel_rti1401
% 	-IC:\Program Files\dSPACE RCPHIL 2014-A\MATLAB\RTI\RTI1401\TLC
% 	-IC:\Program Files\dSPACE RCPHIL 2014-A\matlab\rticanmm\tlc
% 	-IC:\Program Files\dSPACE RCPHIL 2014-A\MATLAB\RTIMMSU\TLC
% 	-IC:\Users\Sebastian\Desktop\DBC_Files\RTICANMMDemo_SimpleModel\demo_simplemodel_rti1401\tlc
% 	-IC:\Program Files\MATLAB\R2014a\rtw\c\tlc\mw
% 	-IC:\Program Files\MATLAB\R2014a\rtw\c\tlc\lib
% 	-IC:\Program Files\MATLAB\R2014a\rtw\c\tlc\blocks
% 	-IC:\Program Files\MATLAB\R2014a\rtw\c\tlc\fixpt
% 	-IC:\Program Files\MATLAB\R2014a\stateflow\c\tlc
% 	-aFoldNonRolledExpr=0
% 	-aInlineInvariantSignals=0
% 	-aInlineParameters=0
% 	-aLocalBlockOutputs=0
% 	-aRollThreshold=5
% 	-aForceBlockIOInitOptimize=0
% 	-aGenerateReport=0
% 	-aGenCodeOnly=0
% 	-aRTWVerbose=0
% 	-aIncludeHyperlinkInReport=0
% 	-aLaunchReport=0
% 	-aGenerateTraceInfo=0
% 	-aForceParamTrailComments=0
% 	-aGenerateComments=1
% 	-aIgnoreCustomStorageClasses=1
% 	-aIncHierarchyInIds=1
% 	-aMaxRTWIdLen=31
% 	-aShowEliminatedStatements=1
% 	-aIncDataTypeInIds=0
% 	-aInsertBlockDesc=0
% 	-aIgnoreTestpoints=0
% 	-aSimulinkBlockComments=1
% 	-aInlinedPrmAccess="Literals"
% 	-aTargetFcnLib="ansi_tfl_table_tmw.mat"
% 	-aLogVarNameModifier="rt_"
% 	-aGenerateFullHeader=1
% 	-aExtMode=0
% 	-aExtModeStaticAlloc=0
% 	-aExtModeTesting=0
% 	-aExtModeStaticAllocSize=1000000
% 	-aExtModeTransport=0
% 	-aRTWCAPISignals=0
% 	-aRTWCAPIParams=0
% 	-aGenerateASAP2=0
% 	-aMatFileLogging=0
% 	-aInitialSimState="RUN"
% 	-aExecutionMode="real-time"
% 	-aExecutionModeNonUI="RTSIM"
% 	-aTimeScaleFactor="1.0"
% 	-aTimeScaleFactorNonUI="OPTION_DISABLED"
% 	-aAssertionMode="OFF"
% 	-aEnableRealTimeTesting=1
% 	-aEnableRealTimeTestingNonUI="ON"
% 	-aCCompilerCommonOpts=""
% 	-aCCompilerOptimizationOptsPopup_="Default"
% 	-aCCompilerOptimizationOpts=""
% 	-aCCompilerOptimizationOptsNonUI="USE_DEFAULT"
% 	-aEnableDataSetStorage=0
% 	-aEnableDataSetStorageNonUI="OFF"
% 	-aAllowReservedHostServiceNums=0
% 	-aRTICfgSetVer=440
% 	-aLoadAfterBuild=1
% 	-aLoadToFlash=0
% 	-aLoadApplNonUI="ON"
% 	-aPlatformSelectionPopup="Platform Name"
% 	-aBoardName="ds1401"
% 	-aBoardNameNonUI="ds1401"
% 	-aNetworkClient=""
% 	-aNetworkClientNonUI="OPTION_DISABLED"
% 	-aTRCOnlyGlobals=0
% 	-aTRCGenerateLabels=1
% 	-aTRCGenerateVirtualBlocks=1
% 	-aTRCGenerateStates=0
% 	-aTRCGenerateDerivatives=0
% 	-aTRCApplySubsystemPermissions=0
% 	-aTRCGenerateParamValues=0
% 	-aTRCIsOmitVdOn=0
% 	-aGenerateTraceInfo=0
% 	-aIgnoreTestpoints=0
% 	-aProtectedModelReferenceTarget=0

   disp('This function will be obsoleted in a future release.') 
   mdl = 'demo_simplemodel';

   sysopen = ~isempty(strmatch(mdl, find_system('type', 'block_diagram'), 'exact'));

   if ~sysopen

      disp([mfilename ': Error: model ' mdl ' is not open. Please open model ' mdl ' and then run ' mfilename ' again.']);

   else

      rtwprivate('rtwattic', 'setBuildDir', 'C:\Users\Sebastian\Desktop\DBC_Files\RTICANMMDemo_SimpleModel\demo_simplemodel_rti1401');
      rtwprivate('ec_set_replacement_flag', 'demo_simplemodel');
      load tlccmd.mat;
      savedpwd = pwd;
      cd ..;
      coder.internal.ModelCodegenMgr.setInstance(modelCodegenMgr);
      tlccmd{end+1} = '-aSLCGUseRTWContext=0';
      feval(tlccmd{:});
      coder.internal.ModelCodegenMgr.setInstance([]);
      rtwprivate rtwattic clean;
      cd(savedpwd);

   end
