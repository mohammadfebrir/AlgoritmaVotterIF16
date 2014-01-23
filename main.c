#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio2.h>

int main(int argc, char *argv[])
{
  char vokal[15] ="aAiIUuEeOo";
  char konsonan[55] ="bBcCdDfFgGhHjJkKlLmMnNpPqQrRsStTvVwWxXyYzZ";
  char pattern[100];
  char text[100];
  char vokal_temp[100];                                   //penampung huruf vokal pattern
  int vokal_temp_pos[100];                                //penampung posisi huruf vokal pattern
  char kons_temp[100];                                    //penampung huruf konsonan pattern
  int kons_temp_pos[100];                                 //penampung posisi huruf konsonan pattern
  int vokal_pos=0, kons_pos =0;                           //inisialisasi posisi awal penampung huruf vokal dan konsonan
  int i, j, k=1, l, x, y=9;                               //inisialisasi variabel pengulangan
  bool status_vokal = false, status_kons = false;
  
  //input text dan pattern
  printf("Masukkan pattern (max.100) : ");
  gets(pattern);
  printf("Masukkan text (max.100)    : ");
  gets(text);
  
  //Preprocessing
  for(i=0; i<strlen(pattern); i++)
  {
    //memisahkan huruf vokal
    for(j=0;j<strlen(vokal);j++)
    {
      if(pattern[i]==vokal[j])
      {
        vokal_temp[vokal_pos] = pattern[i];
        vokal_temp_pos[vokal_pos] = i;   
        vokal_pos++;
      }
    }
    //memisahkan huruf konsonan
    for(j=0;j<strlen(konsonan);j++) 
    {
      if(pattern[i]==konsonan[j])
      {
        kons_temp[kons_pos] = pattern[i];
        kons_temp_pos[kons_pos] = i;   
        kons_pos++;
      }
    }
  }
    
  printf("\nProses Pencocokan\n");
  printf("-----------------");
  
  //inisialisasi penempatan huruf awal
  if(vokal_pos != 0)
  {
    i = vokal_temp_pos[0];
  }
  else
  {
    i = kons_temp_pos[0];
  }
  
  //inisialisasi status pencarian huruf konsonan
  if(kons_pos == 0)
  {
    status_kons = true;
  }

  do
  {
    printf("\n\nUsaha ke-%d\n", k);
    printf("%s\n", text);
    k++;
    x = i; //inisialisasi posisi/penempatan huruf
    
    
    if(vokal_pos != 0)
    {
      for(j=0; j<vokal_pos; j++)
      {       
        gotoxy(x+1, y); //penempatan posisi huruf
        printf("%c", vokal_temp[j]);

        if(vokal_temp[j] != text[x]) //perbandingan huruf vokal dengan huruf di text 
        {
          //perbandingan tidak cocok
          j = vokal_pos; //supaya tidak terjadi pengulangan lagi
          y = y+4;
        }
        else
        {
          x = x + vokal_temp_pos[j+1] - vokal_temp_pos[j];  
          if(j+1 == vokal_pos) //untuk mengecek apakah sudah huruf vokal sudah habis dibandingkan
          {
            x = i + (kons_temp_pos[0] - vokal_temp_pos[0]);
            j = vokal_pos; 
            status_vokal = true;
          }
        }     
      }
    }
    else
    {
      status_vokal = true;
    }
    
    if(status_vokal == true && status_kons == false)
    {
      for(j=0; j<kons_pos; j++)
      {       
        gotoxy(x+1, y); //penempatan posisi huruf
        printf("%c", kons_temp[j]);

        if(kons_temp[j] != text[x]) //perbandingan huruf kons dengan huruf di text 
        {
          //perbandingan tidak cocok
          j = kons_pos; //supaya tidak terjadi pengulangan lagi
          y = y+4; 
          status_vokal = false;
        }
        else
        {
          x = x + kons_temp_pos[j+1] - kons_temp_pos[j];  
          if(j+1 == kons_pos)
          {
            j = kons_pos;
            status_kons = true;
          }
        }     
      }
    }
    i++;
  }  
  while(i < strlen(text) && (status_vokal == false || status_kons == false));
  
  gotoxy(1, y+3); //menempatkan kursor kebawah
  system("PAUSE");
  return 0;
}
