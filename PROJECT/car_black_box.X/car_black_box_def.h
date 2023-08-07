/* 
 * File:   car_black_box_def.h
 * Author: Sushant
 *
 * Created on June 1, 2023, 8:03 PM
 */


#ifndef CAR_BLACK_BOX_DEF_H
#define	CAR_BLACK_BOX_DEF_H

void display_dash_board(char event[], unsigned char speed);
void display_time(void);
void get_time(void);
char login(char key, char reset_pasword );
char login_menu(char key, char reset_menu);
void log_car_event (char *event ,unsigned char speed);
void view_log(unsigned char key, char reset_shift);
void log_action( char *action );
char clear_log (char reset_memory);
char change_time( unsigned char key ,unsigned char reset_time );
void get_password(char *pwd);
char change_password(unsigned char key, char reset_pasword );
void download_log(void);
#endif	/*CAR_BLACK_BOX_DEF_H */


