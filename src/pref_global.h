#ifndef PREF_GLOBAL__H
#define PREF_GLOBAL__H

#include <stdbool.h>
#include "cal.h"
#include "pose.h"
#include "ltlib.h"
#include "pref.h"

bool get_device(struct camera_control_block *ccb);
bool get_pose_setup(reflector_model_type *rm);
bool get_scale_factors(struct lt_scalefactors *sf);
bool get_filter_factor(float *ff);

#endif
