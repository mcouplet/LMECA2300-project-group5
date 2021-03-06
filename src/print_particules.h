#ifndef PRINT_PARTICULES_H
#define PRINT_PARTICULES_H

#include "BOV.h"
#include <math.h>
#include "particle.h"
#include "utils.h"

typedef struct Animation Animation;

struct Animation {
	bov_window_t* window;
	bov_points_t* particles;
	bov_points_t* box;
	double timeout;
	int N;
	bov_points_t* grid;
};

Animation* Animation_new(int N, double timeout,Grid* grid,double scale);
void Animation_free(Animation* animation);

void fillData(GLfloat(*data)[8], Particle** particles, int N);
bov_points_t * load_Grid(Grid* grid,double scale);
void colormap_cell(Particle* p, float color[3]);
void colormap_uni_color(float color[3]);
void colormap_uni_color_2(float color[3]);
void colormap_fs(Particle *p, float color[3], double max_norm);
void colormap_velocity(Particle *p, float color[3], double max_norm);
void colormap_pressure(Particle *p, float color[3], double max_P);
void colours_neighbors(GLfloat(*data)[8], Particle** particles, int index);
void colormap_init_pos(Particle *p, float color[3]);

void display_particles(Particle** particles, Animation* animation, bool end, bool take_screenshot, double t);



#endif
