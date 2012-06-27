#ifndef _GEO_POINT_H_
#define _GEO_POINT_H_

#include <float.h>
#include <stdio.h>
#include <math.h>

#include <openbest-ds/temperatureGlobals.h>
#include <openbest-ds/matrix3.h>

typedef struct 
{
  float latitude;
  float longitude;
  float elevation;
  
  float x;
  float y;
  float z;
} geoPoint;

/**
 * create new geoPoint object (allocation)
 * @returns new geoPoint object with FLT_MAX field values
 */ 
geoPoint* createGeoPointN();

/**
 * create new geoPoint object (copy)
 * @param g object to copy
 * @returns new geoPoint object with copied fields
 */ 
geoPoint* createGeoPointC(geoPoint* g);

/**
 * create new geoPoint object with latitude and longitude given
 * @param latitude latitude of the point
 * @param longitude longitude of the point
 * @returns new geoPoint object with the given fields
 */ 
geoPoint* createGeoPoint2(float latitude, float longitude);

/**
 * create new geoPoint object with latitude, longitude and elevation given
 * @param latitude latitude of the point
 * @param longitude longitude of the point
 * @param elevation elevation of the point
 * @returns new geoPoint object with given fields
 */
geoPoint* createGeoPoint3(float latitude, float longitude, float elevation);

/**
 * computes spherical polar coordinates
 * @param geoPoint geoPoint object to fill its x, y and z fields
 */ 
void computeXYZ(geoPoint* pt);

/**
 * displays the properties of a geoPoint object
 * @param pt parameter to display it's properties
 */ 
void display(geoPoint* pt);

/**
 * Computes the distance between the points. Distance is computed as a great circle on a spherical Earth. Elevation changes are not considered.
 * @param p1 point #1
 * @param p2 point #2
 * @returns the distance of the parameters
 */ 
float distance(geoPoint* p1, geoPoint* p2);

/**
 * Rotates the geoPoint with matrix rot
 * @param pt geoPoint to rotate
 * @param rot rotation matrix
 */ 
void rotateGP(geoPoint* pt, matrix3 rot);

/**
 * Rotates the geoPoint and returns a new, rotated instance
 * @param pt geoPoint to rotate
 * @param rot rotation matrix
 * @returns rotated geoPoint
 */ 
geoPoint rotateGPN(geoPoint* pt, matrix3 rot);

#endif