#ifndef INC_ERROR_H_
#define INC_ERROR_H_

//додавання помилок через по битове або  |
//тим самим можно буде відразу зрозуміти де саме помилка
enum error_status{
	not_errors 		= 0, 	 	//00000000
	not_memory_init = 1 << 0, 	//00000001
	task_scheduler 	= 1 << 1	//00000010
};

typedef enum error_status error_status;

static error_status ERRORS = 0; //якщо помилок в процесы запуску не буде, то ERRORS = 0

#endif /* INC_ERROR_H_ */
