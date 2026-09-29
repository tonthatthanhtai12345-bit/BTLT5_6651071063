var CAN = ["Canh","Tân","Nhâm","Quý","Giáp","Ất","Bính","Đinh","Mậu","Kỷ"];
var CHI = ["Thân","Dậu","Tuất","Hợi","Tý","Sửu","Dần","Mão","Thìn","Tỵ","Ngọ","Mùi"];
function canChi() {
  var txt = document.getElementById("nam").value.trim();
  var y = Number(txt);
  if (txt === "" || !Number.isInteger(y) || y <= 0) {
    alert("Năm không hợp lệ! Vui lòng nhập số nguyên dương.");
    document.getElementById("nam").focus();
    return;
  }
  document.getElementById("kq").value = CAN[y % 10] + " " + CHI[y % 12];
}
