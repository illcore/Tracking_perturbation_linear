//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file B1DetectorConstruction.cc
/// \brief Implementation of the B1DetectorConstruction class

#include "B1DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Tubs.hh"
#include "G4RotationMatrix.hh"
#include "G4SubtractionSolid.hh"
#include "G4IntersectionSolid.hh"
#include "G4VSolid.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::B1DetectorConstruction()
: G4VUserDetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::~B1DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* B1DetectorConstruction::Construct()
{  
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
     
  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //     
  // World
  //
  
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
  
  G4Box* solidWorld =    
    new G4Box("WorldBox",                       //its name
       50*cm, 85*cm, 50*cm);     //its size
      
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "LogicalWorld");            //its name
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking
                      

//Top detector plate #1
  G4Material* shape1_mat = nist->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
  G4ThreeVector pos1 = G4ThreeVector(0*cm, 71.0*cm, 0*cm);
  G4Box* solidEnv1 =    
    new G4Box("SolidBox1",                   
        50*cm, 0.2*cm, 50*cm); 
      
  G4LogicalVolume* TopDet1 =                         
    new G4LogicalVolume(solidEnv1,            
                        shape1_mat,             
                        "LogicSolid1");         
               
    new G4PVPlacement(0,                      
                    pos1,        
                    TopDet1,                
                    "TopHodoscope1",              
                    logicWorld,              
                    false,                   
                    0,                       
                    checkOverlaps);                                      

//Top detector plate #2
  G4ThreeVector pos2 = G4ThreeVector(0*cm, 60.6*cm, 0*cm);
  G4Box* solidEnv2 =    
    new G4Box("SolidBox2",                    
        50*cm, 0.2*cm, 50*cm); 
      
  G4LogicalVolume* TopDet2 =                         
    new G4LogicalVolume(solidEnv2,            
                        shape1_mat,             
                        "LogicSolid2");        
               
    new G4PVPlacement(0,                      
                    pos2,         
                    TopDet2,                
                    "TopHodoscope2",              
                    logicWorld,              
                    false,                   
                    0,                       
                    checkOverlaps);
                                                          
//Top detector plate #3    
  G4ThreeVector pos3 = G4ThreeVector(0*cm, 50.2*cm, 0*cm);
  G4Box* solidEnv3 =    
    new G4Box("SolidBox3",                   
        50*cm, 0.2*cm, 50*cm); 
      
  G4LogicalVolume* TopDet3 =                         
    new G4LogicalVolume(solidEnv3,            
                        shape1_mat,             
                        "LogicSolid3");        
               
    new G4PVPlacement(0,                       
                    pos3,        
                    TopDet3,                
                    "TopHodoscope3",              
                    logicWorld,              
                    false,                   
                    0,                      
                    checkOverlaps);             
//Bottom detector plate #1
  G4ThreeVector pos4 = G4ThreeVector(0*cm, -50.2*cm, 0*cm);
  G4Box* solidEnv4 =    
    new G4Box("SolidBox4",                   
        50*cm, 0.2*cm, 50*cm); 
      
  G4LogicalVolume* BotDet1 =                         
    new G4LogicalVolume(solidEnv4,           
                        shape1_mat,             
                        "LogicSolid4");         
               
    new G4PVPlacement(0,                       
                    pos4,         
                    BotDet1,                
                    "BottomHodoscope1",              
                    logicWorld,              
                    false,                  
                    0,                       
                    checkOverlaps);                                    

//Bottom detector plate #2
  G4ThreeVector pos5 = G4ThreeVector(0*cm, -60.6*cm, 0*cm);
  G4Box* solidEnv5 =    
    new G4Box("SolidBox5",                   
        50*cm, 0.2*cm, 50*cm); 
      
  G4LogicalVolume* BotDet2 =                         
    new G4LogicalVolume(solidEnv5,            
                        shape1_mat,             
                        "LogicSolid5");         
               
    new G4PVPlacement(0,                       
                    pos5,         
                    BotDet2,                
                    "BottomHodoscope2",             
                    logicWorld,              
                    false,                  
                    0,                       
                    checkOverlaps);         
                    
//Bottom detector plate #3    
  G4ThreeVector pos6 = G4ThreeVector(0*cm, -71.0*cm, 0*cm);
  G4Box* solidEnv6 =    
    new G4Box("SolidBox6",                
        50*cm, 0.2*cm, 50*cm); 
      
  G4LogicalVolume* BotDet3 =                         
    new G4LogicalVolume(solidEnv6,            
                        shape1_mat,             
                        "LogicSolid6");         
               
    new G4PVPlacement(0,                       
                    pos6,         
                    BotDet3,              
                    "BottomHodoscope3",              
                    logicWorld,              
                    false,                  
                    0,                      
                    checkOverlaps);         

//Target material       
   G4ThreeVector pos7 = G4ThreeVector(0*cm, 0*cm, 0*cm);
   G4Material* matdet = nist->FindOrBuildMaterial("G4_STAINLESS-STEEL");
   G4Box* solidEnv7 =    
    new G4Box("SolidBox7",                    
        15*cm, 15*cm, 15*cm); 
     
    G4LogicalVolume* MateDetec =                        
    new G4LogicalVolume(solidEnv7,            
                        matdet,             
                        "LogicSolid7");        
               
    new G4PVPlacement(0,                       
                    pos7,        
                    MateDetec,              
                    "TargetMaterial",             
                    logicWorld,              
                    false,                   
                    0,                       
                    checkOverlaps);         

  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
