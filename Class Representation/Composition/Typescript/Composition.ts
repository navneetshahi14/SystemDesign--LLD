class LineItem {
  private productName: string;
  private quantity: number;
  private unitPrice: number;

  constructor(name: string, quantity: number, unitPrice: number) {
    this.productName = name;
    this.quantity = quantity;
    this.unitPrice = unitPrice;
  }

  getSubTotal(): number {
    return this.unitPrice * this.quantity;
  }

  getProductName(): string {
    return this.productName;
  }

  describe(): void {
    console.log(
      `${this.productName} x ${this.quantity} @ $ ${this.unitPrice} = $ ${this.getSubTotal}`,
    );
  }
}

class Order {
  private orderId: string;
  private lineItems: LineItem[];

  constructor(orderId: string) {
    this.orderId = orderId;
    this.lineItems = [];
  }

  addItem(name: string, quantity: number, unitPrice: number): void {
    this.lineItems.push(new LineItem(name, quantity, unitPrice));
  }

  removeItem(product: string): void {
    this.lineItems = this.lineItems.filter(
      (item) => item.getProductName() !== product,
    );
  }

  getTotal(): number {
    return this.lineItems.reduce(
      (total, item) => total + item.getSubTotal(),
      0,
    );
  }

  printReceipt(): void {
    console.log(`Order: ${this.orderId}`);
    for (const item of this.lineItems) {
      item.describe();
    }
    console.log(`Total: $${this.getTotal().toFixed(2)}`);
  }
}

function main(): void {
  const order = new Order("ORD-1001");
  order.addItem("Wireless Mouse", 2, 29.99);
  order.addItem("USB-C Cable", 3, 9.99);
  order.addItem("Laptop Stand", 1, 49.99);

  order.printReceipt();
}

main();
