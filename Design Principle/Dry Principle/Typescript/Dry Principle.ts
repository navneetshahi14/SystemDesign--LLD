export class EmailValidator {
  static isValidEmail(email: string): boolean {
    return email !== null && email.includes("@") && email.includes(".");
  }
}

let email = "navneet.shahi2004@gmail.com";

if (EmailValidator.isValidEmail(email)) {
  // logic
}
