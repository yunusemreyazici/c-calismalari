/*
public static double TersToplam(int m, int n)
Bu fonksiyon m ile n arasindaki tam sayilarin terslerinin toplamini dondurmektedir. Bu fonksiyonun dondurecegi deger asagidaki formulle ifade edilebilir:
Xn 1i i=m
• Fonksiyona verilen ilk argumanin ikinci argumandan kucuk olmasi beklenmektedir. Eger fonksiyona verilen ilk argumanin degeri ikinci argumanin degerinde buyukse yukarida verilen formul m ile n harflerinin yerleri degistirilerek uygulanacaktir.
– m = 4, n = 5 icin ilgili fonksiyon 1 + 1 = 0.45 degerini dondurecektir. Ayni fonksiyon m = 5, 45
n = 4 icin de ayni degeri dondurmelidir.
• TersToplam fonksiyonunun argumanlari pozitif tam sayi olabilecegi gibi negatif tam sayi da olabilir.
1
• m ve n sayilari arasinda 0 olabilir. Bu durumda, yukarida verilen toplam formulune gore 10 degerinin de fonksiyonun dondurecegi toplama dahil edilmesi gerekmektedir. Ne var ki bir sayinin 0 ile bolumu Matematiksel olarak tanimsizdir ve cogu programlama dili tarafindan gecersiz bir islem olarak yorumlanir (Division by zero: daha fazla bilgi icin: https://en.wikipedia.org/wiki/Division_by_zero) Bu nedenle ilgili formulden gelebilecek 10 degerini yazacaginiz kodun yok saymasi gerekmektedir.
– m=-2,n=3icinilgilifonksiyon  1 + 1 +1 +1 +1 =0.333(yaklasikolarak)degerini 21123
dondurecektir. 10 ifadesinin toplama eklenmedigine dikkat ediniz.
• Fonksiyonun argumanlarindan biri pozitif digeri negatif bir sayi ise yazacaginiz kodu mumkun oldugunca az toplama islemi yapacak sekilde optimize ediniz. Negatif ve pozitif toplamlarin bir kisminin birbirini goturebilecegini goz onunde bulundurunuz.
– m = -67, n = 74 argumanlari icin ilgili fonksiyonun dondurecegi deger ile m = 68, n = 74 argumanlari icin ilgili fonksiyonun dondurecegi deger aynidir. Bir diger ifade ile TersToplam(- 67, 74) = TersToplam(68,74) dir.

*/

#include <stdio.h>
double tersToplam(int mdegeri, int ndegeri);
int main(int argc, char const *argv[])
{
    int mdegeri, ndegeri;

    printf("m degeri giriniz... :");
    scanf("%d", &mdegeri);
    printf("n degeri giriniz... :");
    scanf("%d", &ndegeri);

    printf("%lf", tersToplam(mdegeri, ndegeri));

    return 0;
}

double tersToplam(int mdegeri, int ndegeri)
{
    int swapci;
    double dondurucu;
    if (mdegeri > ndegeri) // ilk argumanin kucuk olmasi gerkir. kucuk degilse yer degisim swap islemine tabi tutulur.
    {
        swapci = mdegeri;
        mdegeri = ndegeri;
        ndegeri = swapci;
    }
    if (mdegeri < 0 && ndegeri > 0)
    {
        mdegeri *= (-1);
        if (mdegeri > ndegeri)
        {
            swapci = mdegeri;
            mdegeri = ndegeri;
            ndegeri = swapci;
            for (int i = mdegeri + 1; i <= ndegeri; i++)
            {
                if (i != 0)
                {
                    dondurucu += -(1 / (double)i);
                }   
            }
        }
        else
        {
            for (int i = mdegeri + 1; i <= ndegeri; i++)
            {
                if (i != 0)
                {
                    dondurucu += (1 / (double)i);
                }
            }
        }
    }
    else // buyuk ifin elsesi yani ikisininde + olduğu durum. veya her ikisininde eksi olduğu durum
    {
        for (int i = mdegeri; i <= ndegeri; i++)
        {
            if (i != 0)
            {
                dondurucu += (1 / (double)i);
            }
        }
    }
    return dondurucu;
}