var thu = ["Chủ nhật","Thứ Hai","Thứ Ba","Thứ Tư","Thứ Năm","Thứ Sáu","Thứ Bảy"];
var d = new Date(2023, 8, 1); // 1/9/2023 (tháng tính từ 0)
document.getElementById("kq").innerText =
  "Ngày " + d.getDate() + "/" + (d.getMonth() + 1) + "/" + d.getFullYear() + " là " + thu[d.getDay()];
