var HinhTru = {
  radius: 10,
  height: 15,
  theTich: function () { return Math.PI * this.radius * this.radius * this.height; },
  dienTichToanPhan: function () { return 2 * Math.PI * this.radius * (this.radius + this.height); }
};
var out = "a) Thể tích: " + HinhTru.theTich().toFixed(2);
HinhTru.height = 30;
out += "<br>b) Với height = 30, diện tích toàn phần: " + HinhTru.dienTichToanPhan().toFixed(2);
document.getElementById("kq").innerHTML = out;
