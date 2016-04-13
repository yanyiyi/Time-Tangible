import processing.serial.*;

import processing.video.*;
Movie myMovie;
Serial port; 


int iLight_Counts = 11 ;
int[] iLight_Vals = new int[iLight_Counts], iPre_Light_Vals = new int[iLight_Counts] ;
int[] iInit_Values = new int[iLight_Counts] ;
int[] changeMark  = new int[9];
int cANum;
String nowStat;
int[][] Aver_Stat = new int[10][iLight_Counts] ;
int lf = 10 ;
int[] iWhere = new int[6];
int iNow = 0 ;
void setup() {
  port = new Serial( this, Serial.list()[2], 9600 );
  printArray(Serial.list());
  
  size(1280,800);
  frameRate(30);
  myMovie = new Movie(this, "00.mov");
  myMovie.frameRate(30);
  myMovie.loop();
  // Prints the duration of the movie
  println(myMovie.duration());
  
  
 
      
        for ( int i = 0 ; i < iLight_Counts ; i ++ ) {
            iLight_Vals[i] = 0 ;
            iPre_Light_Vals[i] = 200 ;
        } // for()
  
        // Initial: Delay 3 seconds and read 10 pair numbers.
port.write('1');
port.write('2');
port.write('3');
port.write('4');
port.write('5');
        delay( 10000 ) ;
        nowStat = port.readStringUntil( lf ) ;
        
        for ( int i = 0 ; i < 10 ; i ++ ) {
            delay( 200 ) ;
            nowStat = port.readStringUntil( lf ) ;
            Aver_Stat[i] = int( splitTokens( nowStat, "," ) ) ;
            //println( nowStat ) ;
        } // for
  
        // Get average to 'iInit_Values'.
        for ( int i = 0 ; i < 10 ; i ++ )
          for ( int j = 0 ; j < iLight_Counts ; j ++ )
            iInit_Values[j] += Aver_Stat[i][j] / 10 ;
} //end of Setup
float md,mt;
int playLight = 0;
void draw() {
  

  
  background( 222, 220, 234 ) ;
 
  image(myMovie, 0, 0, width, height);
  // Draws a line on the screen
  // when the movie half-finished
   md = myMovie.duration();
   mt = myMovie.time();
//    float ms = 1.0;
  if (mt < md/5.0 && playLight !=1) {
    line(0, 0, width, height/5);
      port.write('1');
      playLight = 1;
  }else if
    (md/5.0 < mt && mt < md/5.0*2 && playLight !=2){ line(0, 0, width, height/5*2);
  port.write('2');
  playLight =2;
}else if 
  (md/5.0*2 < mt && mt < md/5.0*3 && playLight !=3){ line(0, 0, width, height/5*3);
  port.write('3');
  playLight = 3;
}
  else if
  (md/5.0*3 < mt && mt < md/5.0*4 && playLight !=4){ line(0, 0, width, height/5*4);
  port.write('4');
  playLight = 4;
}
  else if 
  (md/5.0*4 < mt && mt < md/5.0*5 && playLight !=5){ line(0, 0, width, height/5*5);
  port.write('5');
  playLight = 5;
}

 if ((changeMark[6] > 1||changeMark[8] != 0 )&& changeMark[7]>2){

                        mt = myMovie.time();
                        if( (changeMark[6] - changeMark[8]) > -1) mt += 5*(md/30);
                        else mt -= 5*(md/30);
                        if( mt > md ) mt=0; 
                        myMovie.jump(mt);

//myMovie.pause();
//                         ms *= 2.0;
//if( changeMark[6] == 2) ms = -5.0;
 //                         myMovie.speed(ms);
                         myMovie.play();
   //                      print(ms);
                         changeMark[7]=0;
                         } //if Change
 
  if ( 0 < port.available() ) {
    nowStat = port.readStringUntil( lf ) ;
          if ( nowStat != null && nowStat.charAt(0)==6) {
              print( "\n Receiving:" + nowStat ) ;        
                  iLight_Vals = int( splitTokens( nowStat, "," ) ) ;
                  
                  if ( iLight_Vals.length >= iLight_Counts && iLight_Vals[0]==5 ) {

                        int cNum = cANum;
                        sensorLight(cNum); 

                        println(changeMark[0]+":"+changeMark[1]+","+changeMark[2]+","+changeMark[3]+","+changeMark[4]+","+changeMark[5]+",L:"+changeMark[6]+","+changeMark[7]+",R:"+changeMark[8]);
                        println(iWhere[0]+":"+iWhere[1]+","+iWhere[2]+","+iWhere[3]+","+iWhere[4]+","+iWhere[5]);
                  
  
               } // end of Confirm can Read All

          }
    
          if (myMovie.available()) {
    myMovie.read();
  }
  


} //end of Arduino
    
    

  
}//end of draw


int sLCount = 0;
int sPCount = 0;
void sensorLight(int cNum){
        if ((sLCount- changeMark[0])>100 ){
          myMovie.play();
          changeMark[0]= 0;
          changeMark[1]= 0;
          changeMark[2]= 0;
          changeMark[3]= 0;
          changeMark[4]= 0;
          changeMark[5]= 0;
          changeMark[6]= 0;
           changeMark[7]= 0;
           changeMark[8]= 0;
      }
      if ((sLCount-iWhere[0])>100){
      iWhere[1] = 0;
      iWhere[2] = 0;
      iWhere[3] = 0;
      iWhere[4] = 0;
      iWhere[5] = 0;
      iNow = 0;
      }
      
      for ( int i = 1 ; i <=5 ; i++ ){
         
          if(iLight_Vals[i] != 0 && iNow != i) {
              
         iWhere[0]=sLCount;
          iWhere[i]++;
          iNow = i;
          print("??????????????????");
          mt = (md/5)*(i-1);
          myMovie.jump(mt);
          myMovie.play();
          }
      }
      
        for ( int i = 6 ;  i < iLight_Counts ; i ++ ){
                       if ( iLight_Vals[i] - iPre_Light_Vals[i]  >= 25 ){
                       changeMark[0]=sLCount;
                       changeMark[i-5]++;
                       changeMark[7]++;
                       if ((changeMark[1]-changeMark[5])>0 || (changeMark[2]-changeMark[4])>0 ) changeMark[6]++;
                       else if((changeMark[5]-changeMark[4])>0 || (changeMark[4]-changeMark[3])>0 || (changeMark[3]-changeMark[1])>0) changeMark[8]++;
                       else  changeMark[8]++;
                   }

                       iPre_Light_Vals[i] = iLight_Vals[i] ;               
        }
         sLCount++;
         
}
