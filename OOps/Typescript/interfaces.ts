interface IPaymentGateway {
  initiatePayment(amount: number): void;
}

// stripe wala
class StripePayment implements IPaymentGateway {
  initiatePayment(amount: number): void {
    console.log(`Processing payment via Stripe: $${amount}`);
  }
}

// razorpay wala
class RazorPayPayment implements IPaymentGateway {
  initiatePayment(amount: number): void {
    console.log(`Processing payment via RazorPay: $${amount}`);
  }
}

class CheckOutService {
  private paymentGateway: IPaymentGateway;

  constructor(gateway: IPaymentGateway) {
    this.paymentGateway = gateway;
  }

  setPaymentGateway(paymentGateway: IPaymentGateway): void {
    this.paymentGateway = paymentGateway;
  }

  checkout(amount: number): void {
    this.paymentGateway.initiatePayment(amount);
  }
}

function main(): void {
  const stripeGateway: IPaymentGateway = new StripePayment();
  const service = new CheckOutService(stripeGateway);
  service.checkout(120.5); 

  
  const razorpayGateway: IPaymentGateway = new RazorPayPayment();
  service.setPaymentGateway(razorpayGateway);
  service.checkout(150.5);
}
