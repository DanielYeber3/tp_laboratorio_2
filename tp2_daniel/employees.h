
typedef struct
{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;


} sEmployee;


/** \brief Busca si hay espacio en el Array de empleados.
 *
 * \param list[] sEmployee Recibe un array de la estructura.
 * \param len int Recibe el tamaño del array.
 * \return int Retorna el indice del espacio libre (si fue encontrado), si no; recibe -1 que significa que no hay espacio.
 *
 */
int searchFree(sEmployee list[], int len);

/** \brief Inicializa a todos los empleados con isEmpty = 1.
 *
 * \param list[] sEmployee Recibe un array de la estructura.
 * \param len int Recibe el tamaño del array.
 * \return void No retorna nada.
 *
 */
void initEmployees(sEmployee list[], int len);

/** \brief Agrega 1 empleado.
 *
 * \return sEmployee Retorna los valores ingresados en los parametros.
 *
 */
sEmployee addEmployee();

/** \brief Agrega una lista de empleados.
 *
 * \param list[] sEmployee Recibe un array de la estructura.
 * \param len int Recibe el tamaño del array.
 * \return void No retorna nada.
 *
 */
void chargeListOfEmployees(sEmployee list[], int len);

/** \brief Busca un empleado por ID.
 *
 * \param list[] sEmployee Recibe un array de la estructura.
 * \param len int Recibe el tamaño del array.
 * \param id int Recibe el ID a buscar.
 * \return int Retorna el indice donde fue encontrado.
 *
 */
int findEmployeeById(sEmployee list[], int len, int id);

/** \brief Muestra un empleado.
 *
 * \param showAEmployee sEmployee Recibe la estructura de empleados.
 * \return void No retorna nada.
 *
 */
void printOneEmployee(sEmployee showAEmployee);

/** \brief Elimina un empleado del array.
 *
 * \param list[] sEmployee Recibe un array de la estructura.
 * \param len int Recibe el tamaño del array.
 * \param id int Recibe el ID a eliminar.
 * \return int Retorna un valor booleano de si se pudo eliminar o no.
 *
 */
int removeEmployee(sEmployee list[], int len, int id);

/** \brief Ordena la lista de empleados
 *
 * \param list[] sEmployee Recibe un array de la estructura.
 * \param len int Recibe el tamaño del array.
 * \return void No retorna nada.
 *
 */
void sortEmployees(sEmployee list[], int len);

/** \brief Muestra la lista de empleados.
 *
 * \param list[] sEmployee Recibe un array de la estructura.
 * \param len int Recibe el tamaño del array.
 * \return void No retorna nada.
 *
 */
void printEmployees(sEmployee list[], int len);

/** \brief Modifica un empleado de la lista.
 *
 * \param list[] sEmployee Recibe un array de la estructura.
 * \param len int Recibe el tamaño del array.
 * \param int id Recibe el ID a modificar.
 * \return void No retorna nada.
 *
 */
void modifyAnEmployee(sEmployee list[], int len, int id);

/** \brief Hace la cuenta de todos los salarios.
 *
 * \param list[] sEmployee Recibe un array de la estructura.
 * \param len int Recibe el tamaño del array.
 * \return int Retorna el resultado de la suma de todos los salarios.
 *
 */
int AllSalaries(sEmployee list[], int len);

/** \brief Calcula el promedio de todos los salarios.
 *
 * \param list[] sEmployee Recibe un array de la estructura.
 * \param len int Recibe el tamaño del array.
 * \return int Retorna el resultado del promedio.
 *
 */
int averageSalaries(sEmployee list[], int len);

/** \brief Muestra los empleados cuyo salario esta excedido del promedio
 *
 * \param list[] sEmployee Recibe un array de la estructura.
 * \param len int Recibe el tamaño del array.
 * \return void No retorna nada.
 *
 */
void exceedAverage(sEmployee list[], int len);

/** \brief Es un acumulador de los empleados ingresados, este sirve para calcular bien el promedio de los empleados.
 *
 * \param list[] sEmployee Recibe un array de la estructura.
 * \param len int Recibe el tamaño del array.
 * \return int Retorna la cantidad de empleados ingresados.
 *
 */
int accEmployees(sEmployee list[], int len);


