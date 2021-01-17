#include <LCD5110_Basic.h>
LCD5110 LCD(7, 6, 5, 4, 3); //обьявляем дисплей с указанием пинов подключения
extern uint8_t SmallFont[]; //указываем наличие массива со шрифтом SmallFont в библиотеке
extern uint8_t MediumNumbers []; //указываем наличие массива со шрифтом MediumNumbers в библиотеке
void setup() {
     LCD.InitLCD(); //инициализируем дисплей
}
void loop() {
LCD.disableSleep(); //выводим дисплей из режима сна
//LCD.clrScr(); //очищаем дисплей
//LCD.setFont(SmallFont); //устанавливаем шрифт SmallFont
//LCD.print(“Hello World!”, CENTER, 2); //выводим “Hello World!” на второй строчке с равнением по центру
LCD.setFont(MediumNumbers); // устанавливаем шрифт MediumNumbers
for (int i=0; i<=5; i++) {
     LCD.clrScr(); //очищаем экран
     LCD.print(i, CENTER, 20); //выводим значение i по центру 20 строчки
     delay(1000);
}
LCD.enableSleep(); //вводим дисплей в режим сна на время длительной паузы
delay(3000);
}
