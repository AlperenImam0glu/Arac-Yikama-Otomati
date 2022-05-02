int dugme1=2;
int dugme2=3;
int dugme3=4;
int dugme4=5;
int dugme5=6;
int dugme6=7;

int girilenToplamPara=0;
int secimPara=0;
byte rastgeleSayi=0;

bool secimEkrani1=true;
bool secimEkrani2=false;
bool resetEkrani=false;
bool k =true;
bool l =true;
bool m =true;
bool iadeOnay =true;

int girilenPara[5]= {0,0,0,0,0};
int secilenIslem[4]= {0,0,0,0};
int iade[5]= {0,0,0,0,0};
int kasaSayac[5]= {0,0,0,0,0};

int kasaPara[5]= {20,20,10,30,5};

struct hizmetler
{
    int hizmetId;
    char hizmetIsim[10];
    int hizmetMiktari;
    int hizmetUcret;
};

hizmetler hizmetlerVeri[4]= {{1,"kopukleme",30,15}, {2,"yikama   ",50,10}, {3,"kurulama ",100,5}, {4,"cilalama ",20,50}};

void setup(){
    Serial.begin(9600);
    pinMode(dugme1,INPUT);
    pinMode(dugme2,INPUT);
    pinMode(dugme3,INPUT);
    pinMode(dugme4,INPUT);
    pinMode(dugme5,INPUT);
    pinMode(dugme6,INPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);

}

void loop(){

    if( secimEkrani1){
        if(l){
            bilgiler();

            Serial.println("=================================");
            Serial.println("1. buton : 5   TL");
            Serial.println("2. buton : 10  TL");
            Serial.println("3. buton : 20  TL");
            Serial.println("4. buton : 50  TL");
            Serial.println("5. buton : 100 TL");
            Serial.println("6. buton : Bitis");
            Serial.println("=================================");
            l=false;
        }
        islem_ekrani1();
    }
    if(secimEkrani2){
        if(k){
            Serial.println("=================================");
            Serial.println("1. buton : Kopuk   - 15 tl");
            Serial.println("2. buton : Yikama  - 10 tl");
            Serial.println("3. buton : Kurutma - 5  tl");
            Serial.println("4. buton : Cila    - 50 tl");
            Serial.println("5. buton : Iptal");
            Serial.println("6. buton : Bitis");
            Serial.println("=================================");
            k=false;
        }
        islem_ekrani2();
    }
    if(resetEkrani){
        if(m){
            Serial.println("=================================");
            Serial.println("1. buton : RESET");
            Serial.println("2. buton : RESET");
            Serial.println("3. buton : RESET");
            Serial.println("4. buton : RESET");
            Serial.println("5. buton : RESET");
            Serial.println("6. buton : RESET");
            Serial.println("=================================");
            m=false;
        }
        reset();
    }


}

void islem_ekrani1()
{

    if(digitalRead(dugme1)==HIGH){
        Serial.println("5   tl yuklendi");
        girilenPara[0]+=1;
        girilenToplamPara+=5;
        Serial.print("Toplam Para : ");
        Serial.print(+girilenToplamPara);
        Serial.print(" tl\n");
        delay(500);
    }
    if(digitalRead(dugme2)==HIGH){
        Serial.println("10  tl yuklendi");
        girilenPara[1]+=1;
        girilenToplamPara+=10;
        Serial.print("Toplam Para : ");
        Serial.print(+girilenToplamPara);
        Serial.print(" tl\n");
        delay(500);
    }
    if(digitalRead(dugme3)==HIGH){
        Serial.println("20  tl yuklendi");
        girilenPara[2]+=1;
        girilenToplamPara+=20;
        Serial.print("Toplam Para : ");
        Serial.print(+girilenToplamPara);
        Serial.print(" tl\n");
        delay(500);
    }
    if(digitalRead(dugme4)==HIGH){
        Serial.println("50  tl yuklendi");
        girilenPara[3]+=1;
        girilenToplamPara+=50;
        Serial.print("Toplam Para : ");
        Serial.print(+girilenToplamPara);
        Serial.print(" tl\n");
        delay(500);
    }
    if(digitalRead(dugme5)==HIGH){
        Serial.println("100 tl yuklendi");
        girilenPara[4]+=1;
        girilenToplamPara+=100;
        Serial.print("Toplam Para : ");
        Serial.print(+girilenToplamPara);
        Serial.print(" tl\n");
        delay(500);
    }
    if(digitalRead(dugme6)==HIGH && girilenToplamPara >0 ){
        Serial.println("=================================");
        Serial.println("Giris Yapildi");
        for(int i =0; i<5; i++){
            kasaPara[i]+=girilenPara[i];
        }

        for(int i =0; i<5; i++){
            girilenPara[i]=0;
        }
        Serial.print("Toplam Para : ");
        Serial.print(+girilenToplamPara);
        Serial.print(" tl\n");
        Serial.println("=================================");
        secimEkrani1=false;
        secimEkrani2=true;
        l=true;
        delay(500);
    }
}

void islem_ekrani2()
{

    if(digitalRead(dugme1)==HIGH && hizmetlerVeri[0].hizmetMiktari>0 && secilenIslem[0]<hizmetlerVeri[0].hizmetMiktari && girilenToplamPara>secimPara){
        if(girilenToplamPara>=secimPara+15){
            Serial.println("kopuk secildi");
            secilenIslem[0]+=1;
            secimPara+=hizmetlerVeri[0].hizmetUcret;
            Serial.print("Ara Toplam :");
            Serial.print(secimPara);
            Serial.println();
            delay(500);
        }
    }
    if(digitalRead(dugme2)==HIGH && hizmetlerVeri[1].hizmetMiktari>0 && secilenIslem[1]<hizmetlerVeri[1].hizmetMiktari  && girilenToplamPara>secimPara){
        if(girilenToplamPara>=secimPara+10){
            Serial.println("yikama secildi");
            secilenIslem[1]+=1;
            secimPara+=hizmetlerVeri[1].hizmetUcret;
            Serial.print("Ara Toplam :");
            Serial.print(secimPara);
            Serial.println();
            delay(500);
        }
    }
    if(digitalRead(dugme3)==HIGH && hizmetlerVeri[2].hizmetMiktari>0  && secilenIslem[2]<hizmetlerVeri[2].hizmetMiktari  && girilenToplamPara>secimPara){
        if(girilenToplamPara>=secimPara+5){
            Serial.println("kurulama secildi");
            secilenIslem[2]+=1;
            secimPara+=hizmetlerVeri[2].hizmetUcret;
            Serial.print("Ara Toplam :");
            Serial.print(secimPara);
            Serial.println();
            delay(500);
        }
    }
    if(digitalRead(dugme4)==HIGH && hizmetlerVeri[3].hizmetMiktari>0  && secilenIslem[3]<hizmetlerVeri[3].hizmetMiktari  && girilenToplamPara>secimPara){
        if(girilenToplamPara>=secimPara+50){
            Serial.println("cilalama secildi");
            secilenIslem[3]+=1;
            secimPara+=hizmetlerVeri[3].hizmetUcret;
            Serial.print("Ara Toplam :");
            Serial.print(secimPara);
            Serial.println();
            delay(500);
        }
    }
    if(digitalRead(dugme5)==HIGH){
        Serial.println("=================================");
        Serial.println("secimler iptal edildi");
        Serial.println("=================================");
        for(int i =0; i<4; i++){
            secilenIslem[i]=0;
        }
        secimPara=0;
        delay(500);
    }

    if(digitalRead(dugme6)==HIGH && girilenToplamPara >0 ){
        Serial.println("=================================");
        Serial.println("Giris Yapildi");
        Serial.println("=================================");

        rastgeleSayi = random(1,5);


        if(rastgeleSayi==2){
          Serial.println("KIRMIZI ISIK YANIYOR");
            digitalWrite(9,HIGH);
            delay(3000);
            digitalWrite(9,LOW);

            Serial.println("=================================");
            Serial.println("ARIZA PARA SIKISTI");
            Serial.println("PARA IADE EDILIYOR");
            Serial.print("iade : ");
            Serial.print(girilenToplamPara);
            Serial.print("TL");
            Serial.println("");
            Serial.println("=================================");

            paraIade(girilenToplamPara);
            Serial.println("=================================");

            secimPara=0;
            secimEkrani1=false;
            secimEkrani2=false;
            resetEkrani=true;
            m=true;
            k=true;

        }
        else{

          Serial.println("YESIL ISIK YANIYOR");
            digitalWrite(8,HIGH);
            delay(3000);
            digitalWrite(8,LOW);

            paraIade(girilenToplamPara-secimPara);


            if(iadeOnay){
                //yeterli para var
                Serial.println("ONAYLANDI PARA IADE EDILIYOR");
                Serial.print("iade : ");
                Serial.print(girilenToplamPara-secimPara);
                Serial.print("TL");
                Serial.println();
                Serial.println("=================================");

                for(int i =0; i<4; i++){
                    hizmetlerVeri[i].hizmetMiktari-=secilenIslem[i];
                    secilenIslem[i]=0;
                }
            }
            else{
                //yeterli para yok
                Serial.println("=================================");
                Serial.println("YETERLI PARA YOK");
                paraIade(girilenToplamPara);
                Serial.println("=================================");
            }

            secimPara=0;
            secimEkrani1=true;
            secimEkrani2=false;
            k=true;
            iadeOnay=true;
        }


        girilenToplamPara=0;
        delay(500);
    }

}


void reset(){

    if(digitalRead(dugme1)==HIGH){
        girilenToplamPara=0;
        resetEkrani=false;
        secimEkrani1=true;
        secimEkrani2=false;

    }
    if(digitalRead(dugme2)==HIGH){
        girilenToplamPara=0;
        resetEkrani=false;
        secimEkrani1=true;
        secimEkrani2=false;

    }
    if(digitalRead(dugme3)==HIGH){
        girilenToplamPara=0;
        resetEkrani=false;
        secimEkrani1=true;
        secimEkrani2=false;

    }
    if(digitalRead(dugme4)==HIGH){
        girilenToplamPara=0;
        resetEkrani=false;
        secimEkrani1=true;
        secimEkrani2=false;

    }
    if(digitalRead(dugme5)==HIGH){
        girilenToplamPara=0;
        resetEkrani=false;
        secimEkrani1=true;
        secimEkrani2=false;

    }
    if(digitalRead(dugme6)==HIGH ){
        girilenToplamPara=0;
        resetEkrani=false;
        secimEkrani1=true;
        secimEkrani2=false;
    }

}


void paraIade(int para){

    bool y2 =true;

    while(y2){
        if(para /100 >= 1 && kasaPara[4]>0){
            para-=100;
            iade[4]+=1;
            kasaPara[4]-=1;
            kasaSayac[4]+=1;
        }
        else if(para /50 >= 1 && kasaPara[3]>0){
            para-=50;
            iade[3]+=1;
            kasaPara[3]-=1;
            kasaSayac[3]+=1;
        }
        else if(para /20 >= 1 &&kasaPara[2]>0){
            para-=20;
            iade[2]+=1;
            kasaPara[2]-=1;
            kasaSayac[2]+=1;
        }
        else if(para /10 >= 1 && kasaPara[1]>0){
            para-=10;
            iade[1]+=1;
            kasaPara[1]-=1;
            kasaSayac[1]+=1;
        }
        else if(para /5 >= 1 && kasaPara[0]>0){
            para-=5;
            iade[0]+=1;
            kasaPara[0]-=1;
            kasaSayac[0]+=1;
        }

        else if(para<=0){
            for(int i=0; i<5; i++)
            {
                kasaSayac[i]=0;
            }
            y2=false;

        }

        else{
            Serial.println(" kasada yeterli para yok ");
            iadeOnay=false;

            for(int i=0; i<5; i++)
            {
                iade[i]=0;
                kasaPara[i]+=kasaSayac[i];
                kasaSayac[i]=0;
            }

            y2=false;
        }

    }
    y2=true;
    for(int i=0; i<5; i++){
        if(iade[i]!=0)
        {
            if(i==0)
            {

                Serial.print(iade[i]);
                Serial.print(" adet 5 tl");
                Serial.println("");
            }
            if(i==1)
            {
                Serial.print(iade[i]);
                Serial.print(" adet 10 tl");
                Serial.println("");

            }
            if(i==2)
            {
                Serial.print(iade[i]);
                Serial.print(" adet 20 tl");
                Serial.println("");

            }
            if(i==3)
            {
                Serial.print(iade[i]);
                Serial.print(" adet 50 tl");
                Serial.println("");

            }
            if(i==4)
            {
                Serial.print(iade[i]);
                Serial.print(" adet 100 tl");
                Serial.println("");

            }
        }
    }

    for(int i=0; i<5; i++){
        iade[i]=0;
    }

    Serial.println("=================================");

}

void bilgiler(){
  
  int kasaToplam =0;
    kasaToplam =kasaPara[0]*5+kasaPara[1]*10+kasaPara[2]*20+kasaPara[3]*50+kasaPara[4]*100;
  
    Serial.println("---------------------------------");
    Serial.print("|");
    Serial.print("	   -Kasa-");
    Serial.println("");
    Serial.print("|");
    Serial.print("  5 TL -");
    Serial.print(kasaPara[0]);
    Serial.print(" Adet");
    Serial.print("  ");
    Serial.print(" 10 TL -");
    Serial.print(kasaPara[1]);
    Serial.print(" Adet");
    Serial.println("");
    Serial.print("|");
    Serial.print(" 20 TL -");
    Serial.print(kasaPara[2]);
    Serial.print(" Adet");
    Serial.print("  ");
    Serial.print(" 50 TL -");
    Serial.print(kasaPara[3]);
    Serial.print(" Adet");
    Serial.println("	");
    Serial.print("|");
    Serial.print("100 TL -");
    Serial.print(kasaPara[4]);
    Serial.print(" Adet");
    Serial.println("");
    Serial.print("|");
    Serial.print("Toplam para : ");
    Serial.print(kasaToplam);
    Serial.print(" TL");
    Serial.println("");
    Serial.println("---------------------------------");
  

    for(int i =0; i<4; i++)
    {
        Serial.print("|");
        Serial.print(hizmetlerVeri[i].hizmetId);
        Serial.print("-" );
        Serial.print(hizmetlerVeri[i].hizmetIsim);
        Serial.print(": ");
        Serial.print(hizmetlerVeri[i].hizmetMiktari);
        Serial.print(", ");
        Serial.print(hizmetlerVeri[i].hizmetUcret);
        Serial.print(" TL");
        Serial.println();
    }

    Serial.println("---------------------------------");
}
