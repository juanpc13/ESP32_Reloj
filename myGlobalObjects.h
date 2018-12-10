//Manejadores de JSON
utilsSPIFFS uFileS;
utilsJsonFS uJsonF;

//Herramientas de tiempo y convertidor
MyTimeDate mytime;
MyTools mytools;

//Variables del WIFI
String SSID = "";
String PASSWORD = "";

//Varibleas Constantes
const int pinSDA = 18;
const int pinSCL = 19;

//Variables de Configuracion
String dataFilePath = "/data.txt";
#define formatSPIFFS false //Formatear memoria antes de usar


//Varibles Objects
SSD1306Wire  display(0x3c, pinSDA, pinSCL);
OLEDDisplayUi ui(&display);
