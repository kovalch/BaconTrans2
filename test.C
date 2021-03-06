{
  gROOT->Macro("load.C");
  //convert("/nfs/dust/cms/user/kovalch/CRAB/ZeroBias/jme_1.root","test.root","nt_AK4PFCluster");
// //   convert("/afs/desy.de/user/k/kovalch/xxl/af-cms/CMSSW_7_4_6_patch5/src/JMEAnalysis/JMEValidator/test/output_data.root","test_convert_data.root","AK4PFCHS");
  std::string first,second,path;
  first = "/nfs/dust/cms/user/kovalch/GRID-CONTROL_JOBS/Trees/JMEValidatorTree_13TeV_DATA_GOLDEN_2_11_fb_Summer15_25nsV5_DATA_corr_Dv4_L1_151113/dataJetHTRun2015Dv4_";
  second = ".root";
  std::string tmp;
  Long_t *id,*size,*flags,*mt;
  for (int i=1; i<2; i++){
    tmp = std::to_string(i);
    path = first+tmp+second;
    const char *tmp_ = path.c_str();
    // error message if the file does not exist
    if(gSystem->GetPathInfo(tmp_,id,size,flags,mt)==1) std::cout << "file " << path << " does not exist" << std::endl;
    // conversion if the file exists...
    if(!gSystem->GetPathInfo(tmp_,id,size,flags,mt)){ 
      std::cout << "    ++++++    conversion of " << path << " to bacon data format    ++++++" << std::endl;
      convert(first+tmp+second,"/nfs/dust/cms/user/kovalch/GRID-CONTROL_JOBS/Trees/JMEValidatorTree_13TeV_DATA_GOLDEN_2_11_fb_Summer15_25nsV5_DATA_corr_Dv4_L1_151113/BaconTrans/dataJetHTRun2015Dv4_"+tmp+".root","AK4PFCHS");
    }
  }
}
