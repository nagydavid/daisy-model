// bioclimate.h

#ifndef BIOCLIMATE_H
#define BIOCLIMATE_H

#include <std/string.h>
#include <vector.h>

struct Surface;
struct Weather;
struct AttributeList;
struct CropList;
struct Soil;
struct Syntax;
struct SoilWater;

class Bioclimate
{ 
  struct Implementation;
  Implementation& impl;
public:
  // Simulation
  void tick (Surface&, const Weather&, const CropList&, 
	     const Soil&, SoilWater&);

  // Canopy.
public:
  int NumberOfIntervals () const;
  double height (int) const;
  double PAR (int) const;
  double AirTemperature () const;
  double DayLength () const;

  // Manager.
public:
  enum irrigation_from { top_irrigation, surface_irrigation };
  void Irrigate (double flux, double temp, irrigation_from = top_irrigation);
  
  // Create.
public:
  static void load_syntax (Syntax&, AttributeList&);
  Bioclimate (const AttributeList&);
  ~Bioclimate ();
};

#endif BIOCLIMATE_H
