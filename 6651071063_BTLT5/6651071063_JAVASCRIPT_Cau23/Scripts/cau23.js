function tinhLuong() {
  var luong = parseFloat(document.getElementById("luong").value);
  var heso = parseFloat(document.getElementById("heso").value);
  document.getElementById("kq").innerText = isNaN(luong) ? "Lương không hợp lệ!" : Math.round(luong * heso);
}
