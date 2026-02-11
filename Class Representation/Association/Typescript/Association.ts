// Unidirectional Association
class PaymentGateway {
  paymentProcess(amount: number): void {
    console.log(`Processing payment of $${amount}`);
  }
}

class Order {
  private gatway: PaymentGateway;

  constructor(paymentgateway: PaymentGateway) {
    this.gatway = paymentgateway;
  }
  checkOut(): void {
    this.gatway.paymentProcess(100.0);
  }
}

// Bidirectional Association

class Developer {
  private team?: Team;

  setTeam(team: Team): void {
    this.team = team;
  }
}

class Team {
  private devs: Developer[] = [];

  addDevs(dev: Developer): void {
    this.devs.push(dev);
    dev.setTeam(this);
  }
}
