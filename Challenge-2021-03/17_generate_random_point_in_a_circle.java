class Solution {    
    private double r;
    private double x;
    private double y;

    public Solution(double radius, double x_center, double y_center) {
        this.r = radius;
        this.x = x_center;
        this.y = y_center;
    }
    
    public double[] randPoint() {
        double rho = r * Math.sqrt(Math.random());
        double theta = 2.0 * Math.PI * Math.random();
        double[] res = new double[2];
        res[0] = Math.cos(theta) * rho + x;
        res[1] = Math.sin(theta) * rho + y;
        return res;        
    }
}
