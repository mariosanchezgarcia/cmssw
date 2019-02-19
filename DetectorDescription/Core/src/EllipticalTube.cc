#include "DetectorDescription/Core/src/EllipticalTube.h"
#include "DataFormats/Math/interface/GeantUnits.h"

#include <ostream>

using namespace geant_units::operators;

void DDI::EllipticalTube::stream(std::ostream & os) const
{
  os << " xSemiAxis[cm]=" << CONVERT_UNITS_TO( p_[0], cm )
     << " ySemiAxis[cm]=" << CONVERT_UNITS_TO( p_[1], cm )
     << " zHeight[cm]=" << CONVERT_UNITS_TO( p_[2], cm );
}

double DDI::EllipticalTube::volume() const { 
  double volume(0.);
  // who cares major or minor axis? pi * a * b == pi * xhalf * yhalf
  // area of a slice.
  // we KNOW they are all cm... CMS uses cm
  double area(1_pi*p_[0]*p_[1]);
  //volume is z * area.  I'm pretty sure :)
  volume = area * p_[2] * 2;
  return volume; 
}
