/** @type {import('tailwindcss').Config} */
export default {
  content: ['./index.html', './src/**/*.{js,ts,jsx,tsx}'],
  theme: {
    extend: {
      colors: {
        primary: '#6300ef',
        'primary-variant': '#3701b2',
        secondary: '#02dbc6',
        'secondary-variant': '#018786',
        error: '#b10021',
        background: '#fefffe',
        'on-background': '#010001',
      },
    },
  },
  plugins: [],
};
