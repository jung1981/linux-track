#ifndef WEBCAM_DRIVER__H
#define WEBCAM_DRIVER__H

#include "cal.h"

int webcam_init(struct camera_control_block *ccb);
int webcam_shutdown();
int webcam_suspend();
int webcam_change_operating_mode(struct camera_control_block *ccb, 
                             enum cal_operating_mode newmode);
int webcam_wakeup();
int webcam_get_frame(struct camera_control_block *ccb, struct frame_type *f);

extern dev_interface webcam_interface;




#endif