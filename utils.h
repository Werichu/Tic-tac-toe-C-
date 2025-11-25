#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#ifdef _WIN32
  #include<windows.h>
#endif

void limpiar_pantalla()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

#endif // UTILS_H_INCLUDED
