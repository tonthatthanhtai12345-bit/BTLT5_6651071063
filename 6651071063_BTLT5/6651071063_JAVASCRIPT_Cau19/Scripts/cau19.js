var goc = parseFloat(prompt("Số tiền gốc:", 1000000));
var laiSuat = parseFloat(prompt("Lãi suất hàng năm (%):", 7));
var n = parseInt(prompt("Số năm:", 5));
var tong = goc * Math.pow(1 + laiSuat / 100, n);
document.getElementById("kq").innerText =
  "Sau " + n + " năm, tổng số tiền là: " + Math.round(tong).toLocaleString("vi-VN") + " đồng";
