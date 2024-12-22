//=========Biến chứa mã HTLM Website==//
const char MainPage[] PROGMEM = R"=====(
  <!DOCTYPE html> 
  <html>
   <head> 
       <title>MY PAGE</title> 
       <style>
      html {
        font-family: Arial;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
      }
      
      .slidecontainer {
        width: 100%;
      }

      .slider {
        -webkit-appearance: none;
        width: 50%;
        height: 15px;
        border-radius: 5px;
        background: #d3d3d3;
        outline: none;
        opacity: 0.7;
        -webkit-transition: .2s;
        transition: opacity .2s;
      }

      .slider:hover {
        opacity: 1; /*Hiển thị đầy đù khi di chuột qua */
      }

      .slider::-webkit-slider-thumb {
        -webkit-appearance: none; /*Ghi đè lên giao diện mặc định */
        appearance: none;
        width: 25px;
        height: 25px;
        border-radius: 50%;
        background: #4CAF50;
        cursor: pointer;  /*Thuộc tính cursor hiển thị con trỏ chuột khi di chuyển con trỏ vào thành phần*/
      }

      .slider::-moz-range-thumb {
        width: 25px;
        height: 25px;
        border-radius: 50%;
        background: #4CAF50;
        cursor: pointer;
      }
    </style>
       <meta name="viewport" content="width=device-width,user-scalable=0" charset="UTF-8">
   </head>
   <body> 
      <h1>NodeMCU ESP8266 Control Slider</h1> 
      <br><br>
      <div class="slidecontainer">
        <input type="range" min="0" max="100" value="50" class="slider" id="myRange" onchange="slider_onchange()">
        <p>Value : <span id="demo"></span></p>
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
        //------------------------------------------------
        function sendData(pos) {
          var xhttp3 = new XMLHttpRequest();
          xhttp3.onreadystatechange = process_pos;
          xhttp3.open("GET", "setPOS?sliderPOS="+pos, true);
          xhttp3.send();
        } 
        function process_pos(){
            if (this.readyState == 4 && this.status == 200) {
              console.log(this.responseText);
            }
        }
        
        var output_ = document.getElementById("demo");
        output_.innerHTML = slider.value;
        
        function slider_onchange(){
          var slider = document.getElementById("myRange");
          var output = document.getElementById("demo");
    
          slider.oninput = function() {
            output.innerHTML = this.value;
            sendData(output.innerHTML);
          }
        }
        
        //-----------Thiết lập dữ liệu và gửi request Status ---
        //---Ham update duu lieu tu dong---
        var xhttp2 = create_obj();
        setInterval(function() {
          checkstatus();
        }, 1000);
        /*
        setInterval(function() {
          valueee=valueee+10;
          document.getElementById("myRange").value=valueee;
          document.getElementById("demo").innerHTML=valueee;
          
        }, 5000);
        */
        function checkstatus(){
          xhttp2.open("GET","/checkstatus",true);
          xhttp2.onreadystatechange = process_status;//nhận reponse 
          xhttp2.send();
        }
        //-----------Kiểm tra response ------------------
        function process_status(){
          if(xhttp2.readyState == 4 && xhttp2.status == 200){
            //------Update data sử dụng javascript-------------------
            var trangthai_JSON = xhttp2.responseText;
            var Obj = JSON.parse(trangthai_JSON);
            document.getElementById("demo").innerHTML = Obj.slidervalue;
          }
        }
      </script>
   </body> 
  </html>
)=====";
//=========================================//
