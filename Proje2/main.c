#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
    char isim[20];
    char soyad[20];
    char tc[20];
    int tur;
}Musteriler;
typedef struct
{
    int musterino;
    float bakiye;
    Musteriler pMusteri;
}Hesap;
void MusteriEkleme(Hesap *kisiler);
void HesapEkleme(Hesap *kisiler,struct tm *pzaman);
void ParaCekme(struct tm *pzaman);
void ParaYatirma(struct tm *pzaman);
void Havale(struct tm *pzaman);
void Rapor();
void HesapOzeti();
void HesapSilme();
void HesapGoruntuleme();
int main()
{
    Hesap kisi;
    Hesap *pKisi;
    pKisi=&kisi;

    int islem;
    char y,i;
    time_t simdiki_zaman ;
    time(&simdiki_zaman);
    srand(time(NULL));
    struct tm *zaman=localtime(&simdiki_zaman);
    do
    {
        printf("\t\t\t*******************BANKA YAZILIM OTOMASYONU*******************\n\n");
        printf("\t\t\t\t\t1-YENI MUSTERI KAYIT\n");
        printf("\t\t\t\t\t2-HESAP ACMA\n");
        printf("\t\t\t\t\t3-PARA CEKME\n");
        printf("\t\t\t\t\t4-PARA YATIRMA\n");
        printf("\t\t\t\t\t5-HAVALE\n");
        printf("\t\t\t\t\t6-RAPOR AL\n");
        printf("\t\t\t\t\t7-HESAP OZETI\n");
        printf("\t\t\t\t\t8-HESAP SILME\n");
        printf("\t\t\t\t\t9-HESAP GORUNTULEME\n\n");
        devamet:;
        printf("Yapmak istediginiz islemi secin..:");
        scanf("%d",&islem);
        switch(islem)
        {
        case 1:
            MusteriEkleme(pKisi);
            printf("Baska islem yapmak ister misiniz(Evet->E/e | Hayir->H/h):");
            scanf("%c",&y);
            fflush(stdin);
            if(y=='e'||y=='E')
                goto devamet;
            else
                break;
        case 2:
            HesapEkleme(pKisi,zaman);
            printf("Baska islem yapmak ister misiniz(Evet->E/e | Hayir->H/h):");
            scanf("%c",&y);
            fflush(stdin);
            if(y=='e'||y=='E')
                goto devamet;
                break;

        case 3:
            ParaCekme(zaman);
            printf("Baska islem yapmak ister misiniz(Evet->E/e | Hayir->H/h):");
            scanf("%c",&y);
            fflush(stdin);
            if(y=='e'||y=='E')
                goto devamet;
            else
                break;

        case 4:
            ParaYatirma(zaman);
            printf("Baska islem yapmak ister misiniz(Evet->E/e | Hayir->H/h):");
            scanf("%c",&y);
            fflush(stdin);
            if(y=='e'||y=='E')
                goto devamet;
            else
                break;

        case 5:
            Havale(zaman);
            printf("Baska islem yapmak ister misiniz(Evet->E/e | Hayir->H/h):");
            scanf("%c",&y);
            fflush(stdin);
            if(y=='e'||y=='E')
                goto devamet;
            else
                break;

        case 6:
            Rapor();
            printf("Baska islem yapmak ister misiniz(Evet->E/e | Hayir->H/h):");
            scanf("%s",&y);
            fflush(stdin);
            if(y=='e'||y=='E')
                goto devamet;
            else
                break;

        case 7:
            HesapOzeti();
            printf("Baska islem yapmak ister misiniz(Evet->E/e | Hayir->H/h):");
            scanf("%s",&y);
            fflush(stdin);
            if(y=='e'||y=='E')
                goto devamet;
            else
                break;

        case 8:
            HesapSilme();
            printf("Baska islem yapmak ister misiniz(Evet->E/e | Hayir->H/h):");
            scanf("%s",&y);
            fflush(stdin);
            if(y=='e'||y=='E')
                goto devamet;
            else
                break;

        case 9:
            HesapGoruntuleme();
            printf("Baska islem yapmak ister misiniz(Evet->E/e | Hayir->H/h):");
            scanf("%s",&y);
            fflush(stdin);
            if(y=='e'||y=='E')
                goto devamet;
            else
                break;

        }

    }while(i=='e'||i=='E');
}
void MusteriEkleme(Hesap *kisiler)
{
            FILE *fp,*fp2,*fp3,*fp4;
            int musterinumarasi,i;
            int gbkayitno,gtkayitno,gmusterinumarasi;
            int tc_sayac;
            char gtc[20],gisim[20],gsoyad[20];
            do
            {
                printf("Hangi hesap turunu secmek istiyosunuz(Bireysel->1 | Ticari->2):\n");
                scanf("%d",&kisiler->pMusteri.tur);
                fflush(stdin);
            }while(kisiler->pMusteri.tur==1 && kisiler->pMusteri.tur==2);
            printf("Adiniz:");
            scanf("%s",&kisiler->pMusteri.isim);
            fflush(stdin);
            printf("Soyadiniz:");
            scanf("%s",&kisiler->pMusteri.soyad);
            fflush(stdin);
            do
            {
                printf("Tc kimlik numaraniz:");
                scanf("%s",&kisiler->pMusteri.tc);
                tc_sayac=0;
                for(i=0;i<11;i++)
                {
                    if(isdigit(kisiler->pMusteri.tc[i])==0)
                    {
                        tc_sayac++;
                    }
                }
                fflush(stdin);
            }while(tc_sayac!=0 ||strlen(kisiler->pMusteri.tc)!=11);
            musterinumarasi=10000+rand()%90000;
            printf("Musteri numaraniz: %d\n",musterinumarasi);

            if(kisiler->pMusteri.tur==1)
            {
                if((fp=fopen("bireyselmusteriler.txt","a+"))==NULL)
                {
                printf("Dosya acarken hata.");
                exit(1);
                }
                while(!feof(fp))
                {
                    fscanf(fp,"%d %s %s %s %d\n",&gbkayitno,gtc,gisim,gsoyad,&gmusterinumarasi);
                }
                gbkayitno++;
                fprintf(fp,"%d %s %s %s %d\n",gbkayitno,kisiler->pMusteri.tc,kisiler->pMusteri.isim,kisiler->pMusteri.soyad,musterinumarasi);
                fclose(fp);
            }
            if(kisiler->pMusteri.tur==2)
            {
                if((fp=fopen("ticarimusteriler.txt","a+"))==NULL)
                {
                printf("Dosya acarken hata.");
                exit(1);
                }
                while(!feof(fp))
                {
                    fscanf(fp,"%d %s %s %s %d\n",&gtkayitno,gtc,gisim,gsoyad,&gmusterinumarasi);
                }
                gtkayitno++;
                fprintf(fp,"%d %s %s %s %d\n",gbkayitno,kisiler->pMusteri.tc,kisiler->pMusteri.isim,kisiler->pMusteri.soyad,musterinumarasi);
                fclose(fp);
            }
            printf("\nKayitiniz basarili bir sekilde tamamlanmistir.\nLutfen hesap numaranizi kimseyle paylasmayiniz.\n");
}
void HesapEkleme(Hesap *kisiler,struct tm *pzaman)
{
            FILE *fp,*fp2,*fp3;
            char u;
            int hesapnumarasi;
            printf("Musteri numaranizi giriniz:");
            scanf("%d",&kisiler->musterino);
            fflush(stdin);
            hesapnumarasi=1000000+rand()%9000000;
            printf("Hesap numaraniz:%d\n",hesapnumarasi);
            printf("Hesabiniza para yatirmak ister misiniz ?");
            scanf("%c",&u);
            fflush(stdin);
            if((fp2=fopen("rapor.txt","a+"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            if((fp3=fopen("dekont.txt","a+"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            if(u=='e'||u=='E')
            {
                printf("Yatirmak istediginiz bakiyeyi giriniz:");
                scanf("%f",&kisiler->bakiye);
                 fflush(stdin);
                printf("Bakiyeniz : %f\n",kisiler->bakiye);
                fprintf(fp2,"%d %d 2 %f %d %d %d %d %d %d\n",kisiler->musterino,hesapnumarasi,kisiler->bakiye,pzaman->tm_mday,pzaman->tm_mon+1,pzaman->tm_year+1900,pzaman->tm_hour,pzaman->tm_min,pzaman->tm_sec);
                fprintf(fp3,"%d %d 2 %f %d %d %d %d %d %d\n",kisiler->musterino,hesapnumarasi,kisiler->bakiye,pzaman->tm_mday,pzaman->tm_mon+1,pzaman->tm_year+1900,pzaman->tm_hour,pzaman->tm_min,pzaman->tm_sec);
            }
            else
            {
                kisiler->bakiye=0;
                printf("Bakiyeniz : %f\n",kisiler->bakiye);
            }

            if((fp=fopen("hesaplar.txt","a+"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }

            fprintf(fp,"%d %d %f\n",kisiler->musterino,hesapnumarasi,kisiler->bakiye);
            fclose(fp);
            fclose(fp2);
            fclose(fp3);
}
void ParaCekme(struct tm *pzaman)
{
            FILE *fp,*fp2,*fp3,*fp4,*fp5,*fp6;
            int secenek2,gecicimusterino,gecicihno,bmgn,bmghn,value;
            float gecicibakiye,cekilecektutar;
            int sira,mno;
            char ad[20],soyad[20],tc[20];
            char old_name[] = "yenihesaplar.txt";
            char new_name[] = "hesaplar.txt";

            if((fp=fopen("hesaplar.txt","r"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            if((fp2=fopen("yenihesaplar.txt","w+"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            if((fp3=fopen("rapor.txt","a+"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            if((fp4=fopen("dekont.txt","a+"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            if((fp5=fopen("bireyselmusteriler.txt","r"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            if((fp6=fopen("ticarimusteriler.txt","r"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            printf("Bireysel musteriyseniz ->1 || Ticari musteriyseniz-> 2 :");
            scanf("%d",&secenek2);
            fflush(stdin);
            printf("Musteri numaranizi giriniz:");
            scanf("%d",&gecicimusterino);
            fflush(stdin);
            printf("Hesap numaranizi giriniz:");
            scanf("%d",&gecicihno);
            fflush(stdin);
            if(secenek2==1 && fscanf(fp5,"%d %s %s %s %d",&sira,tc,ad,soyad,&mno)!=EOF)
            {
                if(mno==gecicimusterino)
                {
                    while(!feof(fp))
                    {
                      if(fscanf(fp,"%d %d %f",&bmgn,&bmghn,&gecicibakiye)!=EOF)
                        {
                        if((bmgn==gecicimusterino)&&(bmghn==gecicihno))
                        {
                            printf("Bu hesaptan en fazla 750TL cekebilirsiniz.\n");
                            printf("Cekmek istediginiz bakiyeyi giriniz:");
                            scanf("%f",&cekilecektutar);
                            fflush(stdin);
                            if((cekilecektutar<=750)&&cekilecektutar<=gecicibakiye)
                            {
                                gecicibakiye=gecicibakiye-cekilecektutar;
                                fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                                fprintf(fp3,"%d %d 1 %f %d %d %d %d %d %d\n",bmgn,bmghn,cekilecektutar,pzaman->tm_mday,pzaman->tm_mon+1,pzaman->tm_year+1900,pzaman->tm_hour,pzaman->tm_min,pzaman->tm_sec);
                                fprintf(fp4,"%d %d 1 %f %d %d %d %d %d %d\n",bmgn,bmghn,cekilecektutar,pzaman->tm_mday,pzaman->tm_mon+1,pzaman->tm_year+1900,pzaman->tm_hour,pzaman->tm_min,pzaman->tm_sec);
                                printf("Yeni bakiyeniz:%f\n",gecicibakiye);
                            }
                            else
                            {
                                fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                                printf("Para cekme isleminde hataniz olustu.");
                            }


                        }
                        else
                        {
                            fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                        }
                        }
                    }
                }
                else
                {
                    while(!feof(fp))
                    {
                        if(fscanf(fp,"%d %d %f",&bmgn,&bmghn,&gecicibakiye)!=EOF)
                        {
                            fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                        }
                    }
                    printf("Boyle bir Bireysel Musteri yoktur.\n");
                }
            }
            if(secenek2==2 && fscanf(fp6,"%d %s %s %s %d",&sira,tc,ad,soyad,&mno)!=EOF)
            {
                if(mno==gecicimusterino)
                {
                        while(!feof(fp))
                        {
                          if(fscanf(fp,"%d %d %f",&bmgn,&bmghn,&gecicibakiye)!=EOF)
                            {
                            if((bmgn==gecicimusterino)&&(bmghn==gecicihno))
                            {
                                printf("Bu hesaptan en fazla 1500TL cekebilirsiniz.\n");
                                printf("Cekmek istediginiz bakiyeyi giriniz:");
                                scanf("%f",&cekilecektutar);
                                fflush(stdin);
                                if((cekilecektutar<=1500)&&cekilecektutar<=gecicibakiye)
                                {
                                    gecicibakiye=gecicibakiye-cekilecektutar;
                                    fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                                    fprintf(fp3,"%d %d 1 %f %d %d %d %d %d %d\n",bmgn,bmghn,cekilecektutar,pzaman->tm_mday,pzaman->tm_mon+1,pzaman->tm_year+1900,pzaman->tm_hour,pzaman->tm_min,pzaman->tm_sec);
                                    fprintf(fp4,"%d %d 1 %f %d %d %d %d %d %d\n",bmgn,bmghn,cekilecektutar,pzaman->tm_mday,pzaman->tm_mon+1,pzaman->tm_year+1900,pzaman->tm_hour,pzaman->tm_min,pzaman->tm_sec);
                                    printf("Yeni bakiyeniz:%f\n",gecicibakiye);
                                }
                                else
                                {
                                    fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                                    printf("Para cekme isleminde hataniz olustu.");
                                }


                            }
                            else
                            {
                                fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                            }
                            }
                        }
                }
                else
                {
                    while(!feof(fp))
                    {
                        if(fscanf(fp,"%d %d %f",&bmgn,&bmghn,&gecicibakiye)!=EOF)
                        {
                            fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                        }
                    }
                    printf("Boyle bir Bireysel Musteri yoktur.\n");
                }

            }
            fclose(fp);
            fclose(fp2);
            fclose(fp3);
            fclose(fp4);
            remove("hesaplar.txt");
            value = rename(old_name, new_name);
            if(!value)
            {
                printf("\n");
            }
            else
            {
                perror("\n");
            }
}
void ParaYatirma(struct tm *pzaman)
{
            FILE *fp,*fp2,*fp3,*fp4;
            int gecicimusterino,gecicihno,bmgn,bmghn,value;
            float gecicibakiye,yatirilacaktutar;
            char old_name[] = "yenihesaplar.txt";
            char new_name[] = "hesaplar.txt";

            if((fp=fopen("hesaplar.txt","r"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            if((fp2=fopen("yenihesaplar.txt","w+"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            if((fp3=fopen("rapor.txt","a+"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            if((fp4=fopen("dekont.txt","a+"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            printf("Musteri numaranizi giriniz:");
            scanf("%d",&gecicimusterino);
            fflush(stdin);
            printf("Hesap numaranizi giriniz:");
            scanf("%d",&gecicihno);
            fflush(stdin);
                while(!feof(fp))
                {
                  if(fscanf(fp,"%d %d %f",&bmgn,&bmghn,&gecicibakiye)!=EOF)
                    {
                    if((bmgn==gecicimusterino)&&(bmghn==gecicihno))
                    {
                        printf("Bakiyeniz:%f\n",gecicibakiye);
                        printf("Yatirmak istediginiz bakiyeyi giriniz:");
                        scanf("%f",&yatirilacaktutar);
                        fflush(stdin);
                        gecicibakiye=gecicibakiye+yatirilacaktutar;
                        fprintf(fp3,"%d %d 2 %f %d %d %d %d %d %d\n",bmgn,bmghn,yatirilacaktutar,pzaman->tm_mday,pzaman->tm_mon+1,pzaman->tm_year+1900,pzaman->tm_hour,pzaman->tm_min,pzaman->tm_sec);
                        fprintf(fp4,"%d %d 2 %f %d %d %d %d %d %d\n",bmgn,bmghn,yatirilacaktutar,pzaman->tm_mday,pzaman->tm_mon+1,pzaman->tm_year+1900,pzaman->tm_hour,pzaman->tm_min,pzaman->tm_sec);
                        fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                        printf("Yeni bakiyeniz:%f\n",gecicibakiye);
                    }
                    else
                    {
                        fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                    }
                    }
                }
            fclose(fp);
            fclose(fp2);
            fclose(fp3);
            fclose(fp4);
            remove("hesaplar.txt");
            value = rename(old_name, new_name);
            if(!value)
            {
                printf("\n");
            }
            else
            {
                perror("\n");
            }
}
void Havale(struct tm *pzaman)
{
            FILE *fp,*fp2,*fp3;
            int secenek2,gecicichavalehmn,gecicihavalehn,bmgn,bmghn,havalehesapno,value;
            float gecicibakiye,havaleparasi;
            char old_name[] = "yenihesaplar.txt";
            char new_name[] = "hesaplar.txt";
            if((fp=fopen("hesaplar.txt","r"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            if((fp2=fopen("yenihesaplar.txt","w+"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            if((fp3=fopen("dekont.txt","a+"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            printf("Bireysel musteriyseniz ->1 || Ticari musteriyseniz-> 2 :");
            scanf("%d",&secenek2);
            fflush(stdin);
            printf("Musteri numaranizi giriniz:");
            scanf("%d",&gecicichavalehmn);
            fflush(stdin);
            printf("Hesap numaranizi giriniz:");
            scanf("%d",&gecicihavalehn);
            fflush(stdin);

            if(secenek2==1)
            {
                while(!feof(fp))
                {
                    if(fscanf(fp,"%d %d %f",&bmgn,&bmghn,&gecicibakiye)!=EOF)
                    {
                        if((bmgn==gecicichavalehmn)&&(bmghn==gecicihavalehn))
                        {
                            printf("Hesabinizdaki bakiye: %f\n",gecicibakiye);
                            printf("Havale yapmak istediginiz hesap numarasini giriniz:");
                            scanf("%d",&havalehesapno);
                             fflush(stdin);
                            printf("Havale yapmak istediginiz bakiyeyi giriniz:");
                            scanf("%f",&havaleparasi);
                            fprintf(fp3,"%d %d %d %f %d %d %d %d %d %d\n",gecicichavalehmn,gecicihavalehn,havalehesapno,havaleparasi,pzaman->tm_mday,pzaman->tm_mon+1,pzaman->tm_year+1900,pzaman->tm_hour,pzaman->tm_min,pzaman->tm_sec);
                            fflush(stdin);
                            gecicibakiye=gecicibakiye-havaleparasi-(havaleparasi*(2/100));
                            fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                            rewind(fp);
                            while(!feof(fp))
                            {
                                if(fscanf(fp,"%d %d %f",&bmgn,&bmghn,&gecicibakiye)!=EOF)
                                {
                                    if(bmghn==havalehesapno)
                                    {
                                        gecicibakiye=gecicibakiye+havaleparasi;
                                        fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                                    }
                                    else
                                    {
                                        if(bmghn!=gecicihavalehn)
                                            fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                                    }

                                }
                            }
                        }
                    }
                    else
                        printf("Boyle bir hesap kayitli degildir.\n");
                }
            }
            if(secenek2==2)
            {
                while(!feof(fp))
                {
                    if(fscanf(fp,"%d %d %f",&bmgn,&bmghn,&gecicibakiye)!=EOF)
                    {
                        if((bmgn==gecicichavalehmn)&&(bmghn==gecicihavalehn))
                        {
                            printf("Hesabinizdaki bakiye: %f\n",gecicibakiye);
                            printf("Havale yapmak istediginiz hesap numarasini giriniz:");
                            scanf("%d",&havalehesapno);
                             fflush(stdin);
                            printf("Havale yapmak istediginiz bakiyeyi giriniz:");
                            scanf("%f",&havaleparasi);
                             fflush(stdin);
                             fprintf(fp3,"%d %d %d %f %d %d %d %d %d %d\n",gecicichavalehmn,gecicihavalehn,havalehesapno,havaleparasi,pzaman->tm_mday,pzaman->tm_mon+1,pzaman->tm_year+1900,pzaman->tm_hour,pzaman->tm_min,pzaman->tm_sec);
                            gecicibakiye=gecicibakiye-havaleparasi;
                            fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                            rewind(fp);
                            while(!feof(fp))
                            {
                                if(fscanf(fp,"%d %d %f",&bmgn,&bmghn,&gecicibakiye)!=EOF)
                                {
                                    if(bmghn==havalehesapno)
                                    {
                                        gecicibakiye=gecicibakiye+havaleparasi;
                                        fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                                    }
                                    else
                                    {
                                        if(bmghn!=gecicihavalehn)
                                            fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                                    }

                                }
                            }
                        }
                    }
                    else
                        printf("Boyle bir hesap kayitli degildir.\n");
                }
            }
            fclose(fp);
            fclose(fp2);
            fclose(fp3);
            remove("hesaplar.txt");
            value = rename(old_name, new_name);
            if(!value)
            {
                printf("\n");
            }
            else
            {
                perror("\n");
            }
}
void Rapor()
{
            FILE *fp;
            int bmgn,bmghn,artieksi,gun,ay,yil,saat,dakika,saniye;
            float gecicibakiye,toplamcekilenpara=0,toplamyatirilanpara=0;
            if((fp=fopen("rapor.txt","r"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            while(!feof(fp))
            {
                if(fscanf(fp,"%d %d %d %f %d %d %d %d %d %d",&bmgn,&bmghn,&artieksi,&gecicibakiye,&gun,&ay,&yil,&saat,&dakika,&saniye)!=EOF)
                {
                    if(artieksi==1)
                    {
                        toplamcekilenpara=toplamcekilenpara+gecicibakiye;
                    }
                    if(artieksi==2)
                    {
                        toplamyatirilanpara=toplamyatirilanpara+gecicibakiye;
                    }
                }
            }
            printf("Bankadan cekilen toplam para: %f\n",toplamcekilenpara);
            printf("Bankaya yatirilan para: %f\n",toplamyatirilanpara);
            toplamcekilenpara=0;toplamyatirilanpara=0;
            fclose(fp);
}
void HesapOzeti()
{
            FILE *fp;
            int bgun,bay,byil,egun,eay,eyil;
            int gecicimusterino,gecicihno,bmgn,bmghn,artieksi,gun,ay,yil,saat,dakika,saniye;
            float gecicibakiye;
            if((fp=fopen("dekont.txt","r"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            printf("Musteri numaranizi giriniz:");
            scanf("%d",&gecicimusterino);
            fflush(stdin);
            printf("Hesap numaranizi giriniz:");
            scanf("%d",&gecicihno);
            fflush(stdin);
            printf("Hangi tarihler arasinda islem yapmak istediginizi yaziniz...\n");
            printf("Baslangic tarihini bosluk birakarak giriniz(Gun/Ay/Yil) :");
            scanf("%d %d %d",&bgun,&bay,&byil);
            fflush(stdin);
            printf("Bitis tarihini bosluk birakarak giriniz(Gun/Ay/Yil) :");
            scanf("%d %d %d",&egun,&eay,&eyil);
            fflush(stdin);
            while(!feof(fp))
            {
                if(fscanf(fp,"%d %d %d %f %d %d %d %d %d %d",&bmgn,&bmghn,&artieksi,&gecicibakiye,&gun,&ay,&yil,&saat,&dakika,&saniye)!=EOF)
                {
                    if((bgun<=gun)&&(bay<=ay)&&(byil<=yil) && (egun>=gun)&&(eay>=ay)&&(eyil>=yil))
                    {
                        if((gecicimusterino==bmgn)&&(gecicihno==bmghn))
                        {
                            if(artieksi==1)
                            {
                                printf("%d/%d/%d %d:%d:%d zamaninda %f kadar bakiye cektiniz.\n",gun,ay,yil,saat,dakika,saniye,gecicibakiye);
                            }
                            else if(artieksi==2)
                            {
                                printf("%d/%d/%d %d:%d:%d zamaninda %f kadar bakiye yatirdiniz.\n",gun,ay,yil,saat,dakika,saniye,gecicibakiye);
                            }
                            else
                                printf("%d/%d/%d %d:%d:%d zamaninda %f kadar %d hesabina havale yaptiniz.\n",gun,ay,yil,saat,dakika,saniye,gecicibakiye,artieksi);
                        }
                    }
                }
                else
                    printf("Bu tarih araliklarinda herhangi bir islem yapmadiniz.\n");
            }
            fclose(fp);
}
void HesapSilme()
{
            FILE *fp,*fp2;
            int gecicimusterino,gecicihesapno,bmgn,bmghn,value;
            float gecicibakiye;
            char old_name[] = "yenihesaplar.txt";
            char new_name[] = "hesaplar.txt";
            if((fp=fopen("hesaplar.txt","r"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            if((fp2=fopen("yenihesaplar.txt","w+"))==NULL)
            {
                printf("Dosya acarken hata.");
                exit(1);
            }
            printf("Musteri numaranizi giriniz :");
            scanf("%d",&gecicimusterino);
            printf("Silmek istediginiz hesap numaranizi giriniz :");
            scanf("%d",&gecicihesapno);
            while(!feof(fp))
            {
                if(fscanf(fp,"%d %d %f",&bmgn,&bmghn,&gecicibakiye)!=EOF)
                {
                    if((gecicimusterino==bmgn)&&(gecicihesapno==bmghn))
                    {
                            if(gecicibakiye==0)
                            {
                                 printf("Hesabiniz silinmistir.\n");
                            }
                            else
                                printf("Hesabinizda bakiye bulundugundan hesapiniz kapatilamaz.\n");

                    }
                    if(gecicihesapno!=bmghn)
                    {
                        fprintf(fp2,"%d %d %f\n",bmgn,bmghn,gecicibakiye);
                    }
                }
            }
            fclose(fp);
            fclose(fp2);
            remove("hesaplar.txt");
            value = rename(old_name, new_name);
            if(!value)
            {
                printf("\n");
            }
            else
            {
                perror("\n");
            }
}
void HesapGoruntuleme()
{
    FILE *fp;
    int gecicimusterino;
    int gmno,ghno;
    float gbakiye;
    if((fp=fopen("hesaplar.txt","r"))==NULL)
    {
        printf("Dosya acarken hata.");
        exit(1);
    }
    printf("Musteri numaranizi giriniz : ");
    scanf("%d",&gecicimusterino);
    while(!feof(fp))
    {
        if(fscanf(fp,"%d %d %f",&gmno,&ghno,&gbakiye)!=EOF)
        {
            if(gecicimusterino==gmno)
            {
                printf("%d hesabinizda %f kadar bakiyeniz bulunmaktadir.\n",ghno,gbakiye);
            }
        }
        else
            printf("Boyle bir musteri kayitli degildir.\n\n");
    }
    fclose(fp);
}
