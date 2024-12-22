//=========Biến chứa mã HTLM, CSS, JavaScript Website==//
const char MainPage[] PROGMEM = R"=====(
  <!DOCTYPE html> 
  <html>
   <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.5.0/Chart.min.js"></script>
   <head> 
       <title>MY PAGE</title> 
       <style> 
          body {text-align:center;}
          h1 {color:#003399;}
          a {text-decoration: none;color:#FFFFFF;}
           .bt_on {height:50px; width:70px; margin:10px 0;background-color:#11FF00;border-radius:5px;}
           .bt_off {height:50px; width:70px; margin:10px 0;background-color:#FF6F00;border-radius:5px;}
       </style>
       <meta charset="UTF-8">
   </head>
   <body> 
      <h1>ESP8266 Server</h1> 
      <div>
      <p style="text-align:left;">Năng lượng</p>
      <canvas id="myChart" style="width:100%;max-width:600px"></canvas>
       <p style="text-align:right;width:100%;max-width:600px">Thời gian</p>
       <h1 style="text-align:center;width:100%;max-width:600px">Biểu đồ quạt năng lượng<h1>
      </div>
      <p id="demo"></p>
      <script>
        var xValues = [1,2,3,4,5,6,7,8,9,10,11];
        var yValues = [7,8,15,10,11,12,13,14,15,14,13];
        
        var myChartr = new Chart("myChart", {
          type: "line",
          data: {
            labels: xValues,
            datasets: [{
              fill: false,
              lineTension: 0, // Kiểu line connectpoint
              backgroundColor: "rgba(20,222,20,1.0)",// Màu point
              borderColor: "rgba(0,0,255,0.1)",// Màu line connectpoint
              data: yValues
            }]
          },
          options: {
            legend: {display: false},
            scales: {
              yAxes: [{ticks: {min: 6, max:16}}],
            }
          }
        });
        function getRndInteger(min, max) {
          return Math.floor(Math.random() * (max - min)) + min;
        }
        function getRndFloat(min, max) {
          return Math.floor(Math.random() * (max - 1 - min)) + min +  Math.floor(Math.random()*(10))*0.1;
        }
        setInterval(function() {
          let text = "";
          for (let i = 1; i < yValues.length; i++) {
              //text += yValues[i] + "<br>";
                yValues[i-1] = yValues[i];
            }
            yValues[yValues.length-1] = getRndFloat(6,16);
            for (let i = 0; i < xValues.length; i++) {
                xValues[i]++;
            }
          //document.getElementById("demo").innerHTML = text;
          
            myChartr.update();
        }, 1000);
      </script>
   </body> 
  </html>
)=====";
//=========================================//
