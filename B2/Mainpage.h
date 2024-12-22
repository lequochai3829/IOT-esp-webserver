//=========Biến chứa mã HTLM Website==//
const char MainPage[] PROGMEM = R"=====(
  <!DOCTYPE html> 
  <html>
   <head> 
       <title>MY PAGE</title> 
       <style> 
          body {text-align:center;}
          h1 {color:#003399;}
          a {text-decoration: none;color:#FFFFFF;}
           .bt_on {height:50px; width:70px; margin:10px 0;background-color:#11FF00;border-radius:5px;}
           .bt_off {height:50px; width:70px; margin:10px 0;background-color:#FF6F00;border-radius:5px;}
           .bt_setpage {height:30px; width:150px; margin:10px 0;background-color:#003366;border-radius:5px;color:#FFFFFF;}
           html {font-family: Arial; display: inline-block; text-align: center;}
       </style>
       <meta charset="UTF-8">
   </head>
   <body> 
      <h1>ESP8266 Server</h1> 
      <div id="id_page1">
        <div>Trạng thái trên chân D1: <b><pan id="trangthaiD1"></pan></b></div>
        <div>
          <button class="bt_on" onclick="getdata('onD1')">ON</button>
          <button class="bt_off" onclick="getdata('offD1')">OFF</button>
        </div>
      </div>
      <div id="id_page2">
        <div>Trạng thái trên chân D4: <b><pan id="trangthaiD4"></pan></b></div>
        <div>
          <button class="bt_off" onclick="getdata('onD4')">ON</button>
          <button class="bt_on" onclick="getdata('offD4')">OFF</button>
        </div>
        <script>document.getElementById('id_page2').style.display='none'</script>
      </div>
      <div id="reponsetext"></div>
      <div>
      <button id="ShowButton" class="bt_setpage" onclick="button_switch_page_fun()" type="button">Go_PAGE_2</button>
      </div>
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
        //-----------Thiết lập dữ liệu và gửi request-------
        function getdata(url){
          xhttp.open("GET","/"+url,true);
          xhttp.onreadystatechange = process;//nhận reponse 
          xhttp.send();
        }
        //-----------Kiểm tra response--------------------
        function process(){
          if(xhttp.readyState == 4 && xhttp.status == 200){
            //------Updat data sử dụng javascript----------
            ketqua = xhttp.responseText; 
            document.getElementById("reponsetext").innerHTML = ketqua;       
          }
        }
        //------------Kiểm tra trạng thái chân D1 D4------
        function checkstatusD1D4(){
          xhttp.open("GET","checkstatusD1D4",true);
          xhttp.onreadystatechange = process_json;
          xhttp.send();
        }
        //-----------Kiểm tra response-------------------------------
        function process_json(){
          if(xhttp.readyState == 4 && xhttp.status == 200){
            //------Update data sử dụng javascript-------------------
            var trangthaiD1D4_JSON = xhttp.responseText;
            var Obj = JSON.parse(trangthaiD1D4_JSON);
            document.getElementById("trangthaiD1").innerHTML = Obj.D1;
            document.getElementById("trangthaiD4").innerHTML = Obj.D4;
          }
        }
        function button_switch_page_fun() {
          var x = document.getElementById('id_page1');
          var y = document.getElementById('id_page2');
          if (x.style.display === 'none') {
            x.style.display = 'block';
            y.style.display = 'none';
            document.querySelector('#ShowButton').innerText = 'Go_PAGE_2';
            
          } else {
            x.style.display = 'none';
            y.style.display = 'block';
            document.querySelector('#ShowButton').innerText = 'Go_PAGE_1';
          }
        }
        //---Ham update duu lieu tu dong---
        setInterval(function() {
          checkstatusD1D4();
        }, 1000);
      </script>
   </body> 
  </html>
)=====";
//=========================================//
