// ValuMaps — (header)
// File: apps/maps.h

#ifndef VALU_MAPS_H
#define VALU_MAPS_H

// Simple map point
typedef struct {
    int x;
    int y;
} ValuMapPoint;

// Simple map region
typedef struct {
    ValuMapPoint top_left;
    ValuMapPoint bottom_right;
} ValuMapRegion;

// Initialize maps app
void valu_maps_init();

// Center map on a point
void valu_maps_center(ValuMapPoint p);

// Highlight a region
void valu_maps_highlight(ValuMapRegion r);

// Render map to screen
void valu_maps_render();

#endif
