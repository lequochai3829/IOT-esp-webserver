//=========Biến chứa mã HTLM Website==//
const char MainPage[] PROGMEM = R"=====(
  <!DOCTYPE html> 
  <html>
   <head> 
    <title>MY PAGE</title> 
    <style>
      .center {
        margin: auto;
      }
    </style>
    <meta name="viewport" content="width=device-width,user-scalable=0" charset="UTF-8">
   </head>
   <body> 
    <h1> Giá trị analog: </h1>
    <br>
    <div id='bgr'style="width: 600px;height: 16px; background: gray" class="center">
      <div id='val'style="width: 300px;height: 16px; background: blue"></div>
    </div>
    <br>
    <script>
      //-----------Tạo đối tượng request----------------
        function create_obj(){
          td = navigator.appName;
          if(td == "Microsoft Internet Explorer"){
            obj = new ActiveXObject("Microsoft.XMLHTTP");
          }else{
            obj = new XMLHttpRequest();
          }
          return obj;
        }
        var xhttp = create_obj();
        //------------------------------------------------
        window.onload = updateA0;
        function updateA0()
        {
          var xhttp = new XMLHttpRequest();
          xhttp.onreadystatechange = function()
          {
            if(this.readyState == 4 && this.status == 200)
            {
              var valueif  = (parseFloat(xhttp.responseText)/10.24).toFixed(1);
              document.getElementById('val').style.width = ((parseFloat(xhttp.responseText)/10.24).toFixed(1)*6)+"px";
              document.getElementById('val').innerHTML = (parseFloat(xhttp.responseText)/10.24).toFixed(1) +'%';
              
            }     
          }
          xhttp.open("GET","/readA0",true);
          xhttp.send();
        }        
        //-----------Thiết lập dữ liệu và gửi request Status ---
        //---Ham update duu lieu tu dong---
        var xhttp2 = create_obj();
        setInterval(function() {
          updateA0();
        }, 1000);
              
      </script>
   </body> 
  </html>
)=====";
//=========================================//

/*//=========Biến chứa mã HTLM Website==//
const char MainPage[] PROGMEM = R"=====(
  <!DOCTYPE html> 
  <html>
   <head> 
    <title>MY PAGE</title> 
    <style>
      .center {
        margin: auto;
      }
    </style>
    <meta name="viewport" content="width=device-width,user-scalable=0" charset="UTF-8">
   </head>
   <body> 
    <h1> Giá trị analog: </h1>
    <br>
    <div id='bgr'style="width: 600px;height: 16px; background: gray" class="center">
      <div id='val'style="width: 300px;height: 16px; background: blue"></div>
    </div>
    <br>
    <script>
      //-----------Tạo đối tượng request----------------
        function create_obj(){
          td = navigator.appName;
          if(td == "Microsoft Internet Explorer"){
            obj = new ActiveXObject("Microsoft.XMLHTTP");
          }else{
            obj = new XMLHttpRequest();
          }
          return obj;
        }
        var xhttp = create_obj();
        //------------------------------------------------
        window.onload = updateA0;
        function updateA0()
        {
          var xhttp = new XMLHttpRequest();
          xhttp.onreadystatechange = function()
          {
            if(this.readyState == 4 && this.status == 200)
            {
              var valueif  = (parseFloat(xhttp.responseText)/10.24).toFixed(1);
              //if (isNaN(age) || age < 1 || age > 100)
              if(valueif > 50){
                document.getElementById('val').style.background = 'red';
              }
              else
              {
                document.getElementById('val').style.background = 'blue';
              }
              document.getElementById('val').style.width = ((parseFloat(xhttp.responseText)/10.24).toFixed(1)*6)+"px";
              document.getElementById('val').innerHTML = (parseFloat(xhttp.responseText)/10.24).toFixed(1) +'%';
              
            }     
          }
          xhttp.open("GET","/readA0",true);
          xhttp.send();
        }        
        //-----------Thiết lập dữ liệu và gửi request Status ---
        //---Ham update duu lieu tu dong---
        var xhttp2 = create_obj();
        setInterval(function() {
          updateA0();
        }, 1000);
              
      </script>
   </body> 
  </html>
)=====";
//=========================================//

*/
