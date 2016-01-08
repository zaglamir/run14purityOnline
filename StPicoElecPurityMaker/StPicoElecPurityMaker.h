#ifndef StPicoElecPurityMaker_h
#define StPicoElecPurityMaker_h
#include "StRoot/StPicoDstMaker/StPicoTrack.h"
#include "StMaker.h"
class StPicoDst;
class StPicoEvent;
class StPicoDstMaker;
class StPicoMtdHit;
class StPicoTrack;
class TString;
class TH1F;
class TH2F;
class TH3F;
class TFile;
class StPicoElecPurityMaker : public StMaker {
 public:
     StPicoElecPurityMaker(const char *name, StPicoDstMaker *picoMaker, const char *outName);
     virtual ~StPicoElecPurityMaker();
     Bool_t passGoodTrack(StPicoEvent*, StPicoTrack* ); // ZWM
     Bool_t passEIDCuts(StPicoEvent*, StPicoTrack* );   // ZWM
     Bool_t Ismuontrack(StPicoEvent*, StPicoTrack* );
     Bool_t IspassTOFcuts(StPicoTrack*);
     Bool_t IspassBEMCcuts(StPicoTrack*);
     Bool_t passEventCuts(StPicoEvent*);  // ZWM
     Bool_t isBHT1(StPicoEvent*);
     Bool_t isBHT2(StPicoEvent*);
     Bool_t isBHT3(StPicoEvent*);
     Double_t RotatePhi(Double_t phi) const;   
     //virtual Int_t Init();
     //virtual Int_t Make();
     //virtual void  Clear(Option_t *opt="");
     //virtual Int_t Finish();
     Int_t Init();
     Int_t Make();
     void  Clear(Option_t *opt="");
     Int_t Finish();

     void    DeclareHistograms();
     void    WriteHistograms();
     Int_t    FillHistograms(Int_t, StPicoEvent*);

     void  SetDefaultCuts();               // ZWM

      // ZWM Functions
     void   setNSigECuts(float l, float h)  { nSigELow = l;  nSigEHigh = h; };
     void   setNSigPCuts(float l, float h)  { nSigPLow = l;  nSigPHigh = h; };
     void   setNSigKCuts(float l, float h)  { nSigKLow = l;  nSigKHigh = h; };
     void   setNSigPiCuts(float l, float h) { nSigPiLow = l; nSigEHigh = h; };
     void   setvZCuts(float vz, float dvz)  { vZcut = vz; dvZcut = dvz; };
     void   setPrimaryPtCut(float pt)       { ePtCut = pt; };
     void   setPrimaryEtaCut(float et)      { etaCut = et; };
     void   setPrimaryDCACut(float dca)     { dcaCut = dca; };
     void   setNhitsCuts(float dedx, float fit, float ratio) 
        { nhitsdEdxCut = dedx; nhitsFitCut = fit; nhitsRatioCut = ratio; };
     void   setPoECut(float pEl, float pEh) { poeCutLow = pEl; poeCutHigh = pEh; };
     void   setToFBetaCut(float iB)         { tofInvBetaCut = iB; };
     void   setToFLocalyCut(float lY)       { toflocalyCut = lY; };

  private:
   StPicoDstMaker *mPicoDstMaker;
   StPicoDst      *mPicoDst;
   
   // Trigger Tracking
   int numTrigs;
   int trig;
   // Event cut vars
   float vZcut;
   float dvZcut;
   // Track cut vars
   float ePtCut, etaCut, dcaCut;
   float nhitsdEdxCut, nhitsFitCut, nhitsRatioCut;
   float poeCutLow, poeCutHigh;
   float tofInvBetaCut,toflocalyCut;
   
   float nSigELow, nSigEHigh;
   float nSigPLow, nSigPHigh;
   float nSigKLow, nSigKHigh;
   float nSigPiLow, nSigPiHigh;
   TString    mOutName;

     Int_t   mNBadRuns;       

    
   TFile*	   fout;
    //-----event QA-----


    TH1F*      hNEvents[4];
    TH1F*    	htriggerindex[4];
    TH1F*      mVz_vpd[4];
    TH1F*      mVz_tpc[4];
    TH2F*      mVz_vpdtpc[4];
    TH1F*      mdVz[4];
    TH2F*      mdVz_tpcVz[4];
    TH2F*      mVxy[4];
    TH2F*      mVRvsVZ[4];

    TH2F*      mRanking_nPtrks[4];
    TH2F*      mnPtrks_nGtrks[4];
    TH2F*      mnRefMult_nGRefMult[4];
    TH2F*      mnRefMult_nPtrks[4];
    TH2F*      mnRefMult_nGtrks[4];
    TH2F*      mnGRefMult_nPtrks[4];
    TH2F*      mnGRefMult_nGtrks[4];

    TH2F*      mnPtrks_nTofHits[4];
    TH2F*      mnPtrks_nMtdHits[4];

    TH2F*      mnTofHits_nMtdHits[4];
    TH2F*      mnTofMatch_nTofHits[4];
    

    //---------Track QA----------
    //-------TPC information------
    TH1F*      mNptracks[4];
    TH1F*      mNgtracks[4];
    TH1F*      mtrkpt[4];
    TH1F*      mtrkphi[4];
    TH1F*      mtrketa[4];
    TH1F*      mnsigmaK[4];
    TH1F*      mnsigmaE[4];
    TH1F*      mnsigmaP[4];
    TH1F*      mnsigmaPI[4];

    TH2F*      mtrketaphi[4];
    TH2F*      mtrketa_pt[4];
    TH2F*      mtrkphi_pt[4];
    TH2F*      mdedx_Pt[4];

    TH2F*      mnsigmaPI_Pt[4];
    TH2F*      mnsigmaP_Pt[4];
    TH2F*      mnsigmaK_Pt[4];
    TH2F*      mnsigmaE_Pt[4];
    //----TPC information end-----

    //-----TOF INFORMATION start----
    TH2F*      minvsBeta_Pt[4];
    TH2F*      mtofM2_Pt[4];
    //        mp vs nsigmaE
    TH2F*      mtoftray_localY[4];
    TH2F*      mtoftray_localZ[4];
    //TH3F*      mtofhitPosXYZ[4];
    TH2F*      mtoftray_matchflag[4];
    TH2F*      mtoftray_module[4];

    //----TOF information end----
    
    //---------mtd information-------------
    TH2F*      mmtdBeta_Pt[4];
    TH2F*      mmtdBeta_channel[4];
 
    // For Purity
    TH2F*      mnSigmaEvsBeta[4];
    TH2F*      mnSigmaPIvsBeta[4];
    TH2F*      mnSigmaKvsBeta[4];
    TH2F*      mnSigmaPvsBeta[4];
    TH2F*      mdedxvsBeta[4];
    TH2F*      mtofm2vsBeta[4];
	
    TH1F*      hNTracks[4];
    ClassDef(StPicoElecPurityMaker, 1)
};

#endif
